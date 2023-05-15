const express = require('express');
const mongoose = require('mongoose');

// Connect to MongoDB
mongoose.connect('mongodb://localhost:27017/db', {
  useNewUrlParser: true
//   useUnifiedTopology: true
}).then(() => {
  console.log('Connected to MongoDB');
}).catch((error) => {
  console.error('Error connecting to MongoDB:', error);
});

// Create a schema
const userSchema = new mongoose.Schema({
  name: String,
  age: Number,
  email: String
});

// Create a model
const User = mongoose.model('User', userSchema);

const app = express();

// Define a route to fetch all users
app.get('/', async (req, res) => {
  try {
    // Find all users in the database
    const users = await User.find({});
    res.json(users);
  } catch (error) {
    console.error('Error fetching users:', error);
    res.status(500).send('Internal Server Error');
  }
});

// Start the server
app.listen(3000, () => {
  console.log('Server started on port 3000');
});
