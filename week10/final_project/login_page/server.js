const express = require('express');
const sqlite3 = require("sqlite3").verbose();
const app = express();
const port = 3000;
let sql;

app.use(express.static('D:\\VS-20230610T091643Z-001\\VS\\course\\CS50\\week10\\final_project\\login_page\\public'));
app.use(express.json());
const db = new sqlite3.Database("./users.db", sqlite3.OPEN_READWRITE, (err) => {
    if (err) return console.error(err.message);
})
sql = `CREATE TABLE users(email INTEGER PRIMARY KEY,password, retyped_pass,first_name,last_name, address)`;
db.run(sql);
db.run()

//app.post('/', (req, res) => {
///   console.log(30)
//    const { email, password, retyped_pass, first_name, last_name, address } = req.body;
//    sql = `INSERT INTO users(email,password, retyped_pass,first_name,last_name, address)`;
//    db.run(sql, [email, password, retyped_pass, first_name, last_name, address], (err))
//    sql = `SELECT *FROM users`;
//    db.all(sql, [], (err, row) => {
//       if (err) return console.error(err.message);
//       row.forEach(row => {
//           console.log(row);
//       })
// })
//});
sql = `INSERT INTO users(password, retyped_pass,first_name,last_name, address) VALUES(?,?,?,?,?)`;
db.run(sql,
    ["mike", "das", "dasdas", "dsada", "dsadas"], (err) => {
        if (err) return console.error(err.message);
    });

app.listen(port, () => console.log(`Server has started on port:${port}`));