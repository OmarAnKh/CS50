const express = require('express');
const app = express();
const port = 3000;

app.use(express.static('D:\\VS-20230610T091643Z-001\\VS\\course\\CS50\\week10\\final_project\\login_page\\public'));
app.use(express.json());

app.post('/', (req, res) => {
    const { name } = req.body;
    console.log(name);
    if (!name) {
        return res.status(400).send({ status: 'failed' })
    }
    res.status(200).send({ status: 'recieved' });
})

app.listen(port, () => console.log(`server has stared on port:${port}`))