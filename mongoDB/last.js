const express = require('express');
const mongoose = require('mongoose');

// Connect to MongoDB
mongoose.connect('mongodb://localhost:27017/db', {
  useNewUrlParser: true,
  useUnifiedTopology: true,
  serverSelectionTimeoutMS: 30000
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

// Add a new user
const newUser = new User({
  name: 'John Doe',
  age: 30,
  email: 'john.doe@example.com'
});

newUser.save()
  .then(() => {
    console.log('User added successfully');
  })
  .catch((error) => {
    console.error('Error adding user:', error);
  });

// Define a route to fetch the first user
app.get('/', async (req, res) => {
  try {
    // Find the first user in the database
    const user = await User.findOne({});
    res.json(user);
  } catch (error) {
    console.error('Error fetching user:', error);
    res.status(500).send('Internal Server Error');
  }
});

// Start the server
app.listen(3000, () => {
  console.log('Server started on port 3000');
});
