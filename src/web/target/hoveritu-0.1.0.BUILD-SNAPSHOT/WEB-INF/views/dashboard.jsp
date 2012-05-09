<<<<<<< HEAD
<!--
 File: control-panel.html 
 Author: Mozhan Soltani
 Date: 06-05-2012
 -->

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns = "http://www.w3.org/1999/xhtml">
 <head>
  <title>Hovercraft Web Interface</title>
  <script type="text/javascript">
    function displayInc()
   {
    alert("You have clicked on the Increase button!");
   }
   
   function displayDec()
   {
    alert("You have clicked on the Decrease button!");
   }

   function displayQ()
   {
    alert("You have clicked on the Q button!");
   }
   
   function displayW()
   {
    alert("You have clicked on the W button!");
   }
   
   function displayE()
   {
    alert("You have clicked on the E button!");
   }
   
   function displayA()
   {
    alert("You have clicked on the A button!");
   }
   
   function displayS()
   {
    alert("You have clicked on the S button!");
   }
   
   function displayD()
   {
    alert("You have clicked on the D button!");
   }
   
   function displayBreak()
   {
    alert("You have clicked on the Break button!");
   }
  </script>
  <style type="text/css">
  <!-- positioning the elements-->
   body {font-size:110%;font-style:normal;font-family:calibri;}
   .container {
     width:100%;
	 height:100%;
	 padding:0%;
   }
   .leftSide{
     width:20%;
	 height:100%;
	 float:left;
	 padding:0%;
   }
   .leftSide-up1{
     width:20%;
	 float:left;
	 padding:1%;
   }
   .leftSide-up2{
     width:60%;
     float:left;
	 padding:0%;
	 margin:2%;
   }
   .leftSide-mid1{
     width:20%;
	 height:30%;
	 float:left;
	 padding:1%;
   }
   .leftSide-mid2{
     width:60%;
	 height:30%;
	 float:left;
	 padding:1%;
	 margin:2%;
   }
   .left_box1{
     width:30%;
	 height:60%;
	 border:2px solid black;
	 padding:40%;
   }
   .leftSide-down1{
     width:20%;
	 height:30%;
	 float:left;
	 padding:1%;  
   }
   .leftSide-down2{
     width:60%;
	 height:35%;
	 float:left;
	 padding:1%;
	 margin:2%;  
   }
   .left_box2{
     width:115%;
	 height:90%;
	 border:2px solid black;
	 padding:2%;
	 margin:2%;
   }
   .increase_button{
     padding:1%;
	 margin:5%;
	 text-align:center;
   }
   .decrease_button{
     padding:1%;
	 margin:5%;
	 text-align:center;
   }
   .center{
     width:57%;
	 height:100%;
	 padding:1%;
	 float:left;
   }
   .free_space{
     width:80%;
	 height:25%;
	 padding:7%;
	 float:left;
   }
   .rightSide{
     width:15%;
	 height:100%;
	 padding:1%;
	 float:left;
   }
   .free_space2{
     width:10%;
	 padding:42%;
	 margin:0%;
	 float:left;
   }
   .rightSide-mid{
     width:100%;
	 height:15%;
	 float:left;  
   }
   .right_box1{
     border:2px solid black;
	 width:70%;
	 padding:10%;
   }
   .current_status{
     padding:1%;
	 margin:0%;
   }
   .rightSide-down{
     width:100%;
	 float:left;
   }
   .free_space3{
     width:20%;
	 float:left;
	 padding:30%;
	 margin:0%;
   }
  </style>
 </head>
 <body>
  <div id="container" class="container">
   <div id="leftSide" class="leftSide">
    <div id="leftSide-up1" class="leftSide-up1">   
    </div> <!--leftSide-up1--> 
	<div id="leftSide-up2" class="leftSide-up2"> 
	 <div id="left_texts">
      <p> 
		<br />
		<br />
        <b>Battery Level:</b>	
      </p> 
	  <p> 
        <b>Pressure Level:</b>	
      </p>
     </div>
	</div> <!--leftSide-up2-->
	<div id="leftSide-mid1" class="leftSide-mid1">   
    </div> <!--leftSide-mid1-->
	<div id="leftSide-mid2" class="leftSide-mid2">
	<p>   
      <b>GPS Information:</b>	
    </p>
    <div id="left_box1" class="left_box1" >
    </div> 	
	</div> <!--leftSide-mid2-->
	<div id="leftSide-down1" class="leftSide-down1">   
    </div> <!--leftSide-down1-->
	<div id="leftSide-down2" class="leftSide-down2">
	 <p>  
       <b>Hovercarft Speed:</b>	
     </p>
     <div id="left_box2" class="left_box2" >
	  <br />
      <b style="padding:8%;">Current Speed: ...</b> 
	  <br />
	  <div id="increase_button" class="increase_button">
       <img border="0" src="increasespeed.png" onclick = "displayInc()"
      	  alt="Increase Button" width="140" height="35"/>
	  </div>
	  <div id="decrease_button" class="decrease_button">
       <img border="0" src="decreasespeed.png" onclick = "displayDec()"
     	  alt="Increase Button" width="140" height="35"/>
	  </div>
     </div> 	
	</div> <!--leftSide-down2-->	
   </div> <!--leftSide-->
   <div id="center" class="center">
    <div id="free_space" class="free_space">
	</div>
	<div id="logo">
    <img border="0" src="Propeller_3_white.gif" alt="HoverIT logo"
		 width="750" height="250" />
    </div>
   </div> <!--center-->
   <div id="rightSide" class="rightSide">
    <div id="free_space2" class="free_space2">
	</div>
	<div id="right_text1">
     <p> 
       <b>Current Status:</b> 
     </p> 
    </div>
	<div id="rightSide-mid" class="rightSide-mid">
	 <div id="right_box1" class="right_box1">
      <b class="current_status"> Going forward ...</b>
     </div>
	</div> <!--rightSide-mid-->
	<div id="rightSide-down" class="rightSide-down">
	 <div id="free_space3" class="free_space3">
	 </div>
	 <div id="Q_button" style="padding:2%;float:left;">
      <img border="0" src="qbutton.png" onclick = "displayQ()" 
	      alt="Q Button"  width="45" height="35" />
     </div>
	 <div id="W_button" style="padding:2%;float:left;">
      <img border="0" src="wbutton.png" onclick = "displayW()" 
	      alt="W Button"  width="45" height="35" />
     </div>
	 <div id="E_button" style="padding:2%;float:left;">
      <img border="0" src="ebutton.png" onclick = "displayE()" 
	      alt="E Button"  width="45" height="35" />
     </div>
	 <div id="A_button" style="padding:2%;float:left;">
      <img border="0" src="abutton.png" onclick = "displayA()" 
	      alt="A Button"  width="45" height="35" />
     </div>
	 <div id="S_button" style="padding:2%;float:left;">
      <img border="0" src="sbutton.png" onclick = "displayS()" 
	      alt="S Button"  width="45" height="35" />
     </div>
	 <div id="D_button" style="padding:2%;float:left;">
      <img border="0" src="dbutton.png" onclick = "displayD()" 
	      alt="D Button"  width="45" height="35" />
     </div>
	 <div id="break_button" style="padding:2%;float:left;">
      <img border="0" src="breakbutton.png" onclick = "displayBreak()"  
	      alt="break Button"  width="152" height ="38" />
     </div>
	</div> <!--right side-down-->
   </div> <!--right side-->
  </div> <!--container--> 
 </body>
</html>
=======
<!--
 File: control-panel.html 
 Author: Mozhan Soltani
 Date: 06-05-2012
 -->

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns = "http://www.w3.org/1999/xhtml">
 <head>
  <title>Hovercraft Web Interface</title>
  <script type="text/javascript">
    function displayInc()
   {
    alert("You have clicked on the Increase button!");
   }
   
   function displayDec()
   {
    alert("You have clicked on the Decrease button!");
   }

   function displayQ()
   {
    alert("You have clicked on the Q button!");
   }
   
   function displayW()
   {
    alert("You have clicked on the W button!");
   }
   
   function displayE()
   {
    alert("You have clicked on the E button!");
   }
   
   function displayA()
   {
    alert("You have clicked on the A button!");
   }
   
   function displayS()
   {
    alert("You have clicked on the S button!");
   }
   
   function displayD()
   {
    alert("You have clicked on the D button!");
   }
   
   function displayBreak()
   {
    alert("You have clicked on the Break button!");
   }
  </script>
  <style type="text/css">
  <!-- positioning the elements-->
   body {font-size:110%;font-style:normal;font-family:calibri;}
   .container {
     width:100%;
	 height:100%;
	 padding:0%;
   }
   .leftSide{
     width:20%;
	 height:100%;
	 float:left;
	 padding:0%;
   }
   .leftSide-up1{
     width:20%;
	 float:left;
	 padding:1%;
   }
   .leftSide-up2{
     width:60%;
     float:left;
	 padding:0%;
	 margin:2%;
   }
   .leftSide-mid1{
     width:20%;
	 height:30%;
	 float:left;
	 padding:1%;
   }
   .leftSide-mid2{
     width:60%;
	 height:30%;
	 float:left;
	 padding:1%;
	 margin:2%;
   }
   .left_box1{
     width:30%;
	 height:60%;
	 border:2px solid black;
	 padding:40%;
   }
   .leftSide-down1{
     width:20%;
	 height:30%;
	 float:left;
	 padding:1%;  
   }
   .leftSide-down2{
     width:60%;
	 height:35%;
	 float:left;
	 padding:1%;
	 margin:2%;  
   }
   .left_box2{
     width:115%;
	 height:90%;
	 border:2px solid black;
	 padding:2%;
	 margin:2%;
   }
   .increase_button{
     padding:1%;
	 margin:5%;
	 text-align:center;
   }
   .decrease_button{
     padding:1%;
	 margin:5%;
	 text-align:center;
   }
   .center{
     width:57%;
	 height:100%;
	 padding:1%;
	 float:left;
   }
   .free_space{
     width:80%;
	 height:25%;
	 padding:7%;
	 float:left;
   }
   .rightSide{
     width:15%;
	 height:100%;
	 padding:1%;
	 float:left;
   }
   .free_space2{
     width:10%;
	 padding:42%;
	 margin:0%;
	 float:left;
   }
   .rightSide-mid{
     width:100%;
	 height:15%;
	 float:left;  
   }
   .right_box1{
     border:2px solid black;
	 width:70%;
	 padding:10%;
   }
   .current_status{
     padding:1%;
	 margin:0%;
   }
   .rightSide-down{
     width:100%;
	 float:left;
   }
   .free_space3{
     width:20%;
	 float:left;
	 padding:30%;
	 margin:0%;
   }
  </style>
 </head>
 <body>
  <div id="container" class="container">
   <div id="leftSide" class="leftSide">
    <div id="leftSide-up1" class="leftSide-up1">   
    </div> <!--leftSide-up1--> 
	<div id="leftSide-up2" class="leftSide-up2"> 
	 <div id="left_texts">
      <p> 
		<br />
		<br />
        <b>Battery Level4:</b>	
      </p> 
	  <p> 
        <b>Pressure Level:</b>	
      </p>
     </div>
	</div> <!--leftSide-up2-->
	<div id="leftSide-mid1" class="leftSide-mid1">   
    </div> <!--leftSide-mid1-->
	<div id="leftSide-mid2" class="leftSide-mid2">
	<p>   
      <b>GPS Information:</b>	
    </p>
    <div id="left_box1" class="left_box1" >
    </div> 	
	</div> <!--leftSide-mid2-->
	<div id="leftSide-down1" class="leftSide-down1">   
    </div> <!--leftSide-down1-->
	<div id="leftSide-down2" class="leftSide-down2">
	 <p>  
       <b>Hovercarft Speed:</b>	
     </p>
     <div id="left_box2" class="left_box2" >
	  <br />
      <b style="padding:8%;">Current Speed: ...</b> 
	  <br />
	  <div id="increase_button" class="increase_button">
       <img border="0" src="increasespeed.png" onclick = "displayInc()"
      	  alt="Increase Button" width="140" height="35"/>
	  </div>
	  <div id="decrease_button" class="decrease_button">
       <img border="0" src="decreasespeed.png" onclick = "displayDec()"
     	  alt="Increase Button" width="140" height="35"/>
	  </div>
     </div> 	
	</div> <!--leftSide-down2-->	
   </div> <!--leftSide-->
   <div id="center" class="center">
    <div id="free_space" class="free_space">
	</div>
	<div id="logo">
    <img border="0" src="Propeller_3_white.gif" alt="HoverIT logo"
		 width="750" height="250" />
    </div>
   </div> <!--center-->
   <div id="rightSide" class="rightSide">
    <div id="free_space2" class="free_space2">
	</div>
	<div id="right_text1">
     <p> 
       <b>Current Status:</b> 
     </p> 
    </div>
	<div id="rightSide-mid" class="rightSide-mid">
	 <div id="right_box1" class="right_box1">
      <b class="current_status"> Going forward ...</b>
     </div>
	</div> <!--rightSide-mid-->
	<div id="rightSide-down" class="rightSide-down">
	 <div id="free_space3" class="free_space3">
	 </div>
	 <div id="Q_button" style="padding:2%;float:left;">
      <img border="0" src="qbutton.png" onclick = "displayQ()" 
	      alt="Q Button"  width="45" height="35" />
     </div>
	 <div id="W_button" style="padding:2%;float:left;">
      <img border="0" src="wbutton.png" onclick = "displayW()" 
	      alt="W Button"  width="45" height="35" />
     </div>
	 <div id="E_button" style="padding:2%;float:left;">
      <img border="0" src="ebutton.png" onclick = "displayE()" 
	      alt="E Button"  width="45" height="35" />
     </div>
	 <div id="A_button" style="padding:2%;float:left;">
      <img border="0" src="abutton.png" onclick = "displayA()" 
	      alt="A Button"  width="45" height="35" />
     </div>
	 <div id="S_button" style="padding:2%;float:left;">
      <img border="0" src="sbutton.png" onclick = "displayS()" 
	      alt="S Button"  width="45" height="35" />
     </div>
	 <div id="D_button" style="padding:2%;float:left;">
      <img border="0" src="dbutton.png" onclick = "displayD()" 
	      alt="D Button"  width="45" height="35" />
     </div>
	 <div id="break_button" style="padding:2%;float:left;">
      <img border="0" src="breakbutton.png" onclick = "displayBreak()"  
	      alt="break Button"  width="152" height ="38" />
     </div>
	</div> <!--right side-down-->
   </div> <!--right side-->
  </div> <!--container--> 
 </body>
</html>
>>>>>>> a90f937b019fcd8576785b514a0b63110c747d28
 