const express = require('express')
const app = express()

app.listen(3000, ()=>
{
    console.log("Application is stated and listening on port 3000")
})

app.get("/", (req,res)=>{
    res.sendFile(__dirname+"/index2.html")
})