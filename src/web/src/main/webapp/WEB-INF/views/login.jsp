
<!--
 File: login_panel.html 
 Author: Fangzhou Cao	
 Date: 08-05-2012
 -->

<html>
<head>
<style type="text/css">
#form1
{
 position: absolute;
 left: 550px;
  top: 250px;  
}

#pic1
{
 position:absolute;
 left: 300px;
 top: 30px;
  height: 350px;
  width: 850px;
}



</style>


<script type= "text/javascript">
function loginCheck()
{
if(document.getElementById("username").value == "" || document.getElementById("password").value == "")
{
 alert("please fill in both your username and username");
 return false;
}
else{
 return true;
}
}

function login(){
 alert("Login is clicked!");
}

function register(){
 alert("register is clicked!");
}
function forgetPSW(){
 alert("forgetPSW is clicked!");
}
	


</script>
</head>


<body>
<div id="container"  align="center">
<img id="pic1" src="pictures/Propeller_2_trans.gif"  alt="Welcome to hoverIT" />

<form id="form1" name="loginPage" action="" onsubmit="return loginCheck()">
<hr />
username: <input type="text" id="username" /> <br />
Password: <input type="password" id="password" /> <br /> 

<input type="submit" value="Log in" onclick="login()" /> <br /> <br /> <br />
<input type="button" value="I'm new here" onclick="register()" /> 
<input type="button" value="forget your password?" onclick="forgetPSW()" />
 <br />
<input type="checkbox" name="keepinfo" value="keepIn" /> keep me log in
</form>

</div>

</body>
</html>