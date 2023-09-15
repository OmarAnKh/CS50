const express = require('express')
const Items = require('../models/items')
const auth = require('../middleware/auth')
const multer = require('multer')
const sharp = require('sharp')
const router = new express.Router()
const items = multer({
    dest: 'items',
    limits: {
        fileSize: 1000000
    },
    fileFilter(req, file, cb) {

        if (!file.originalname.match(/\.(jpg|jpeg|png)$/)) {
            return cb(new Error('please upload a jpg or jpeg or png file '))
        }
        cb(undefined, true)
    }
})

router.post('/items',  items.single('items'), async (req, res) => {
    const img = await sharp(req.file.buffer).resize({ width: 300 }).png.toBuffer()

    const { name, total_amount, red, green, blue, black, white, description } = req.body;
    const item = new Items({ name, total_amount, red, green, blue, black, white, img, description });
    await item.save();
})


module.exports = router