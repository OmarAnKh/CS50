const express = require('express');
const User = require('../models/users');
const auth = require('../middleware/auth');

const router = new express.Router();

router.get('/sign-in', (req, res) => {
    res.render('sign-in', {
        title: 'sign-in'
    });
});

router.get('/sign-up', (req, res) => {
    res.render('sign-up', {});
});

router.get('/some/other/endpoint', (req, res) => {
    res.send();
});

router.post('/users/login', async (req, res) => {
    try {
        const user = await User.findByCredentials(req.body.email, req.body.password);
        const token = await user.generateAuthToken();

        res.send({ user: user.getpublicProfile(), token });
    } catch (e) {
        res.status(400).send();
    }
});

router.post("/users", async (req, res) => {
    const { email, name, password, address, age } = req.body;

    try {
        const existingUser = await User.findOne({ email });

        if (existingUser) {
            return res.status(400).send({ error: "Email already in use" });
        }

        const user = new User({ email, name, password, address, age });
        const token = await user.generateAuthToken();
        await user.save();
        res.status(201).send({ user, token });
    } catch (e) {
        res.status(500).send(e);
    }
});

router.get('/users', async (req, res) => {
    try {
        const users = await User.find();
        
        res.send(users);
    } catch (e) {
        res.status(500).send();
    }
});

router.patch('/update', async (req, res) => {
    
    const updates = Object.keys(req.body)
    const allowedUpdates = ['name', 'address', 'age']
    const isValiOperation = updates.every((update) => allowedUpdates.includes(update))
    if (!isValiOperation) {
        return res.status(400).send({ error: 'Invalid Updates!' })
    }
    try {
        const user = await User.findById(req.user._id)
        updates.forEach((update) => {
            user[update] = req.body[update]

        })
        await user.save()

        if (!user) {
            return res.status(404).send()
        }
        res.send(user)
    } catch (e) {
        res.status(400).send(e)
    }
})

router.get('/to-register', (req, res) => {
    res.render('to-register', {});
});

module.exports = router;