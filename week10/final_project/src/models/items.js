const mongoose = require('mongoose')
const validator = require('validator')



const itemsSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true
    },
    total_amount: {
        type: Number,
        required: true,

    }, red: {
        type: Number,
        required: true,

    }, green: {
        type: Number,
        required: true,

    }
    , blue: {
        type: Number,
        required: true,

    }
    , black: {
        type: Number,
        required: true,

    }, white: {
        type: Number,
        required: true,

    }, img: {
        type: Buffer,
        
    }, description: {
        type: String,
        required: true,
        lowercase: true
    }

})

const Items = mongoose.model('items', itemsSchema);
module.exports = Items;