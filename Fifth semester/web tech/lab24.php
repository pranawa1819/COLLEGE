<?php
// Database connection parameters
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "test_db";

// Create connection
$conn = new mysqli($servername, $username, $password);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Create database
$sql = "CREATE DATABASE IF NOT EXISTS $dbname";
if ($conn->query($sql) === TRUE) {
    echo "Database created successfully or already exists<br>";
} else {
    echo "Error creating database: " . $conn->error . "<br>";
}

// Select the database
$conn->select_db($dbname);

// Create table
$sql = "CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
)";
if ($conn->query($sql) === TRUE) {
    echo "Table 'users' created successfully or already exists<br>";
} else {
    echo "Error creating table: " . $conn->error . "<br>";
}

// Insert a new record into the users table
$sql = "INSERT INTO users (username, email) VALUES ('john_doe', 'john@example.com')";
if ($conn->query($sql) === TRUE) {
    echo "New record created successfully<br>";
} else {
    echo "Error inserting record: " . $conn->error . "<br>";
}

// Update the email of a user
$sql = "UPDATE users SET email = 'john.doe@example.com' WHERE username = 'john_doe'";
if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully<br>";
} else {
    echo "Error updating record: " . $conn->error . "<br>";
}

// Delete a user by username
$sql = "DELETE FROM users WHERE username = 'john_doe'";
if ($conn->query($sql) === TRUE) {
    echo "Record deleted successfully<br>";
} else {
    echo "Error deleting record: " . $conn->error . "<br>";
}

// Select all users from the users table
$sql = "SELECT * FROM users";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Output data of each row
    while($row = $result->fetch_assoc()) {
        echo "id: " . $row["id"]. " - Username: " . $row["username"]. " - Email: " . $row["email"]. " - Created at: " . $row["created_at"]. "<br>";
    }
} else {
    echo "0 results";
}

// Close connection
$conn->close();
echo"<br><br>";
echo"This is my first php program";
echo"<br> Hello World";

echo "<br>";
echo "<br>";
$name="Pranawa K.C";
echo $name."<br>";
echo "The reverse of string is ".strrev($name)."<br>";
echo "The string in upper case is ".strtoupper($name)."<br>";
echo "The string in lower case is ".strtolower($name);
echo "<br>";
echo "<br>";

$firstName = "Pranawa";
$lastName = "K.C";

// Concatenation operator (.)
$fullName = $firstName . " " . $lastName;
echo "Full Name using concatenation operator: " . $fullName . "<br>";

// Concatenation assignment operator (.=)
$greeting = "Hello";
$greeting .= ", " . $fullName . "!";
echo "Greeting using concatenation assignment operator: " . $greeting;
?>