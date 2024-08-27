<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <table border="1px">
        <tr>
            <th>Id</th>
            <th>Name</th>
        </tr>
        <tr>
            <?php
                $servername='localhost';
                $username='root';
                $password='';
                $dbname='webtech';
                $conn=mysqli_connect($servername,$username,$password,$dbname);
                
                if($conn){
                    echo "Connection Successful<br>";
                }
                
                echo "Illustration of for loop<br>";
                for($i=0;$i<10;$i++){
                    echo $i."<br>";
                }
                $sql="select * from lab25";
                $result=mysqli_query($conn,$sql);
                if(mysqli_num_rows($result)>0){
                while($row=mysqli_fetch_assoc($result)){
                    $id=$row["id"];
                    $name=$row["name"];
                    echo"
                    <tr>
                    <td style='padding:5px;width:50px;text-align:center;'>$id</td>
                    <td style='padding:5px;width:50px'>$name</td>

                    </tr>
                    
                    ";
                }}
            ?>
        </tr>
    </table>  
</body>
</html>