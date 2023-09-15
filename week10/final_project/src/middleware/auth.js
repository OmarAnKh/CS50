const jwt = require('jsonwebtoken')
const User = require('../models/users')


const auth = async (req, res, next) => {
    console.log(10)
    try {

        const token = await req.cookies.token;
        console.log(token)
        const decoded = jwt.verify(token, 'thisismyonlinestore')
        const user = await User.findOne({ _id: decoded._id, 'tokens.token': token })

        if (!user) {
            throw new Error()
        }
        req.token = token
        req.user = user
        next()
    } catch (e) {
        res.status(401).send({ error: 'please authenticate' })
    }
}


module.exports = auth