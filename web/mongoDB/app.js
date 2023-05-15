const mongoose = require('mongoose');
const express = require('express')

const app = express()

// console.log("start");
const connectionParams = {
useNewUrlParser: true,
useUnifiedTopology: true,
};

try {
mongoose.connect('mongodb://0.0.0.0:27017/test', connectionParams);
console.log("Connected to database successfully");
} catch (error) {
console.log(error);
console.log("Could not connect database!");
}

const studentSchema = new mongoose.Schema({
name: String,
marks: Number,
address: String
});

const Student = mongoose.model('Student', studentSchema);

const satvam = new Student({ name: 'Satvam', marks: 0 });
console.log(satvam.name);
satvam.save();

const Om = new Student({ name: 'Om', marks: 1 });
console.log(Om.name);
Om.save();

Student.updateOne({name:'Om'}, {name:'Mehdi'})
.then(console.log("hua"))

Student.deleteOne({name:'Satvam'})
.then(console.log('hua'))

// const Om = {
//     name: 'Om',
//     marks: 10,
//     address: 'Dahisar'
// }

// Student.create(Om)
// .then(error => console.log(error))

// Student.find({address: {$not: {$in: ['Dahisar']}}})
// .then(error => console.log(error))


app.get('/', async (req, res) => {
try {
    const users = await Student.find();
    res.send(users);
} catch (err) {
    console.log(err);
    res.status(500).json({ message: 'Error retrieving users' });
}
});


app.listen(3000, () => {
    console.log('Running')
 })