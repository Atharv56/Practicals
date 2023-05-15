const mongoose = require('mongoose')
const express = require('express')
const app = express()
const connectionParams = {
    useNewUrlParser: true
    // useUnifiedTopolody: true
}

try{
    mongoose.connect('mongodb://localhost/27017/db', connectionParams)
    console.log('Connected successfully')

}
catch(err){
    console.log(err)
    console.log('Could not connect')
}

const student = new mongoose.Schema({
    name: String,
    marks: Number,
    location: String
})

const details = mongoose.model('Student',student)

const Atharv = new details({name: "Atharv", marks: 99, location: "Borivali"})
console.log(Atharv)

Atharv.save().then(()=>{
    console.log('User added')
})
.catch(()=> {
    console.log('Error adding user')
})

const Sid = new details({name: "Sid", marks: 35, location: "Andheri"})
console.log(Sid.marks)

Sid.save()
console.log(details)
//Uptil here was question 3
// console.log(student.find())
// app.get('/', async (req, res) => {
//     try {
//       const students = await Atharv.find({});
//       res.render('students', { students });
//     } catch (err) {
//       console.log('Error retrieving students:', err);
//       res.status(500).send('Internal Server Error');
//     }
//   });
  
//   // Set the view engine to render HTML (assuming you have installed the 'ejs' view engine)
//   app.set('view engine', 'ejs');
  
//   // Start the server
//   app.listen(3000, () => {
//     console.log('Server started on port 3000');
//   });