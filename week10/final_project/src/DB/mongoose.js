const mongoose = require('mongoose')

mongoose.connect('mongodb://127.0.0.1:27017/online-store', {
    useNewUrlParser: true,
    useUnifiedTopology: true,
    createIndexes: true,
    useFindAndModify: false
});