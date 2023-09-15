const express = require('express')
const path = require('path')
const fs = require('fs')
require('./DB/mongoose')
const hbs = require('hbs')
const User = require('./models/users')
const auth = require('./middleware/auth')
const bodyParser = require('body-parser')
const bcryptjs = require('bcryptjs')
const userRouter = require('./routers/users')
const cookieParser = require('cookie-parser');
const pageRouter = require('./routers/pages')
const itemsRouter = require('./routers/items')
const app = express()
const port = 3000


const publicPath = path.join(__dirname, '../public')
const viewPath = path.join(__dirname, '../templates/views')
const partialsPath = path.join(__dirname, '../templates/partials')


app.use(express.static(publicPath))
app.set('view engine', 'hbs')
app.set('views', viewPath)
hbs.registerPartials(partialsPath)


app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(userRouter)
app.use(pageRouter)
app.use(itemsRouter)
app.use(cookieParser());

app.post('/logout', auth, async (req, res) => {
    console.log(10)
    try {
        req.user.tokens = req.user.tokens.filter((token) => req.token !== token.token)
        await req.user.save()
        res.send()
    }
    catch (error) {
        res.status(400).send(error)
    }
});


app.listen(port, () => {
    console.log('server is up on port ' + port)
})
