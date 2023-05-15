const express = require('express')
const app = express()

var bodyParser = require("body-parser")

app.use(bodyParser.urlencoded({extended: false}))

app.get('/', (req,res)=>{
    res.sendFile(__dirname+'/index.html')
})

app.post('/submit', (req, res)=>
{
    var name = req.body.firstName + " "+ req.body.lastName
    console.log(name)
    res.send(name + ' Submitted successfully')
})

app.listen(3000, (req, res)=>  {
    console.log('Sever is running on port 3000')
})