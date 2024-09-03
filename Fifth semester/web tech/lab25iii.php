<?php 
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
$database = "school"; 
// Create connection to MySQL server 
$conn = new mysqli($servername, $username, $password); 
// Check connection 
if ($conn->connect_error) { 
die("Connection failed: " . $conn->connect_error); 
} else { 
echo "****CONNECTION HAS BEEN ESTABLISHED!!*****"; 
} 
// Create the database if it doesn't exist 
$sql = "CREATE DATABASE IF NOT EXISTS $database"; 
if ($conn->query($sql) === TRUE) { 
echo "<br>**DATABASE IS CREATED OR ALREADY EXISTS!**"; 
}
else{
die("DATABASE CREATION FAILED!!<br>" . $conn->error); 
}
// Select the database 
$conn->select_db($database); 
// Create the students table if it doesn't exist 
$sql = "CREATE TABLE IF NOT EXISTS students ( 
id INT AUTO_INCREMENT PRIMARY KEY, 
 
 
    first_name VARCHAR(50), 
    last_name VARCHAR(50), 
    age INT, 
    grade VARCHAR(10) 
)"; 
// Execute the query to create the table 
if ($conn->query($sql) === TRUE) { 
    echo "<br>**TABLE IS CREATED OR ALREADY EXISTS!**"; 
} else { 
    die("TABLE CREATION FAILED!!<br>" . $conn->error); 
} 
// Insert data into the students table 
$sql = "INSERT INTO students (first_name, last_name, age, grade) VALUES 
('Shiv', 'Bhattarai', 15, '10th'), 
('Pranawa', 'K.C', 21, 'Bachelor'), 
('Yunika', 'Shrestha', 19, '12th')"; 
// Execute the insert query 
if ($conn->query($sql) === TRUE) { 
    echo "<br>**DATA INSERTED INTO TABLE SUCCESSFULLY!**"; 
} else { 
    echo "<br>DATA INSERTION FAILED! " . $conn->error; 
} 
// Select data from the students table 
$sql = "SELECT id, first_name, last_name, age, grade FROM students"; 
$result = $conn->query($sql); 
?>