<?php 
echo "For loop output:\n</br>"; 
for ($i = 1; $i <= 5; $i++) { 
echo " $i</br>\n"; 
} 
echo "\n"; 
echo "While loop output:\n</br>"; 
$i = 6; 
while ($i <= 10) { 
echo " $i</br>\n"; 
$i++; 
} 
echo "\n"; 
echo "Do while loop output:\n</br>"; 
$i = 11; 
do { 
echo " $i</br>\n"; 
$i++; 
} while ($i <= 15); 
echo "\n"; 
echo "For each loop output:\n</br>"; 
$fruits = array("Apple", "Apricot", "Avocado", "Grapes","Orange"); 
foreach ($fruits as $fruits) { 
echo " $fruits</br>\n"; 
} 

echo"<br><br>";

$server = "localhost"; 
$username = "root"; 
$password = ""; 
$conn = new mysqli($server, $username, $password); 
if ($conn->connect_error) { 
die("!CONNECTION UNSUCESSFUL!<br>" . $conn->connect_error); 
} else { 
echo ("******THE CONNECTION HAS BEEN ESTABLISHED! 
*****<br>"); 
} 
echo"<br><br>";


?>