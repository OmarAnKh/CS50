const express = require('express')
const User = require('../models/users')
const auth = require('../middleware/auth')
const cookieParser = require('cookie-parser');


const router = new express.Router();
router.use(cookieParser());

router.get('', auth, (req, res) => {
    res.render('index', {
        title: 'online-store',
        name: "dinosaur t shirt",
        src: 'img/Urban-Outfitters.jpeg'
    })
})

router.get('/cart', auth, (req, res) => {

    res.render('cart', {
        title: 'cart',
        name: "dinosaur t shirt",
        src: 'img/Urban-Outfitters.jpeg'
    })
})


router.get('/women', auth, (req, res) => {
    res.render('women', {

    })
})
router.get('/men', auth, (req, res) => {
    res.render('men', {

    })
})
router.get('/kids', auth, (req, res) => {
    res.render('kids', {

    })
})
router.get('/shoes', auth, (req, res) => {
    res.render('shoes', {

    })
})
router.get('/my-account', auth, async (req, res) => {
    const user = await req.cookies.user;
    const email = await req.cookies.email;
    const age = await req.cookies.age;
    const address = await req.cookies.address;
    res.render('Account', {
        user,
        email,
        age,
        address


    })
})
module.exports = router