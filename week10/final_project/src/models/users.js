const mongoose = require('mongoose')
const validator = require('validator')
const bcrypt = require('bcryptjs')
const jwt = require('jsonwebtoken')
const userSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true,
        trim: true
    },
    email: {
        type: String,
        unique: true,
        required: true,
        trim: true,
        lowercase: true,
        validator(value) {
            if (!validator.isEmail(value)) {
                throw new Error('email is no valid')
            }
        }
    },
    age: {
        type: String,
        required: true,

    }, password: {
        type: String,
        required: true,
        trim: true,
        validator(value) {
            if (value.length < 6) {
                throw new Error('The password must be longer')
            }
        }
    },
    address: {
        type: String,
        required: true,
        trim: true,
    },
    items: [{
        item: {
            type: Number
        }
    }],
    Admin: {
        type: Boolean,
        default: false

    }, avatar: {
        type: Buffer,
        
    }
    ,
    tokens: [{
        token: {
            type: String
        }
    }]
})
userSchema.methods.getpublicProfile = function () {
    const user = this
    const userObject = user.toObject()
    delete userObject.password
    delete userObject.tokens
    return userObject
}

userSchema.methods.generateAuthToken = async function () {
    const user = this
    const token = jwt.sign({ _id: user._id.toString() }, 'thisismyonlinestore')
    user.tokens = user.tokens.concat({ token })
    await user.save()
    return token


}

userSchema.statics.findByCredentials = async (email, password) => {

    const user = await User.findOne({ email })
    if (!user) {
        throw new Error('Unable to login')
    }
    const isMatch = await bcrypt.compare(password, user.password)
    if (!isMatch) {
        throw new Error('Unable to login')
    }
    return user
}


userSchema.pre('save', async function (next) {
    const user = this

    if (user.isModified('password')) {
        user.password = await bcrypt.hash(user.password, 8)
    }

    next()
})

const User = mongoose.model('User', userSchema)

module.exports = User