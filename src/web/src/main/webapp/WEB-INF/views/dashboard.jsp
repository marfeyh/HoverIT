<!--
 File: control-panel.html 
 Author: Mozhan Soltani
 Date: 01-05-2012
 Copyright 2012 Mozhan Soltani,
 The program is distributed under the terms of the GNU General Public License.
 -->

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns = "http://www.w3.org/1999/xhtml">
 <head>
  <title>Hovercraft Web Interface</title>
  <style type="text/css">
   body
	{
	  margin:0;
      padding:0;
	}
   .container
	{
	  position:relative;
      width:100%;
    }
   .logo
    {
      position:absolute;
	  margin:10px;
      left:470px;
    }
   .left_text1
    {
      position:absolute;
	  top:120px;
	  left:90px;
	  margin:0px;
    }
   .left_text2
    {
      position:absolute;
	  top:150px;
	  left:90px;
	  margin:0px;
    }
   .left_text3
    {
      position:absolute;
	  top:200px;
	  left:90px;
	  margin:0px;
    }
   .left_text4
    {
      position:absolute;
	  top:370px;
	  left:90px;
      width:200px;
	  margin:0px;
    }
   .left_box1
	{
	  position:absolute;
	  top:240px;
      left:90px;
      padding:30px;
      border:5px solid black;
      margin:0px;
	}
   .left_box2
	{
	  position:absolute;
	  top:410px;
      left:90px;
      padding:34px;
      border:5px solid black;
      margin:0px;
	}
	.increase_button
    {
      position:absolute;
	  top:70px;
      left:5%;
	  margin:20px;
    }
   .decrease_button
    {
      position:absolute;
	  top:120px;
      left:5%;
	  margin:20px;
    } 
   .right_text1
    {
      position:absolute;
	  top: 240px;
	  right:160px;
    }
   .right_box1
	{
	  position:absolute;
	  top:280px;
      right:125px;
      padding:10px;
      border:5px solid black;
	  margin:0px;
	}
   .Q_button
    {
      position:absolute;
	  top:440px;
      right:230px;
    } 
   .W_button
    {
      position:absolute;
	  top:440px;
      right:170px;
    } 
   .E_button
    {
      position:absolute;
	  top:440px;
      right:110px;
    } 
   .A_button
    {
      position:absolute;
	  top:484px;
      right:230px;
    }
   .S_button
    {
      position:absolute;
	  top:484px;
      right:170px;
    }
   .D_button
    {
      position:absolute;
	  top:484px;
      right:110px;
    }
   .break_button
    {
      position:absolute;
	  top:535px;
      right:105px;
	  border:0px;
	  padding:0px;
	  margin:0px;
    }
  </style>
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
 </head>

 <body>
  <div class="container">
   <div class="logo">
    <img border="0" src="Hover3.png" alt="HoverIT logo"
		 width="350" height="280" />
   </div>
   <div class="left_text1">
    <p> 
      <font size="5" face="Times New Roman" color="black">
       <b>Battery Level:</b> 	
      </font>
    </p> 
   </div>
   <div class="left_text2">   
	<p> 
      <font size="5" face="Times New Roman" color="black">
	   <b>Pressure Level:</b>
      </font>
    </p> 
   </div>
   <div class="left_text3">
    <p class="serif"> 
      <font size="4.5" face="Times New Roman" color="black">
       <b>GPS Information:</b> 
      </font>
    </p> 
   </div>
   <div class="left_box1" >
    <p class="serif"> 
     <font size="4.5" face="Times New Roman" color="white">
      <b>GPS informa</b> 
     </font>
    </p>
   </div> 
   <div class="left_text4">
    <p class="serif"> 
     <font size="4.5" face="Times New Roman" color="black">
      <b>Hovercraft Speed:</b> 
     </font>
    </p> 
   </div>
   <div class="left_box2">
  
    <font size="4.5" face="Times New Roman" color="black">
      <b>Current Speed: ...</b> 
    </font>
    <br />
    <br />
    <br />
    <br />
    <br />
    <br />
	<div class="increase_button">
     <img border="0" src="increasespeed.png" onclick = "displayInc()"
      	  alt="Increase Button"  width="150" height="35" />
	</div>
	<div class="decrease_button">
     <img border="0" src="decreasespeed.png" onclick = "displayDec()"
     	  alt="Increase Button"  width="150" height="35" />
	</div>
   </div> 
   <div class="right_text1">
    <p> 
      <font size="4.5" face="Times New Roman" color="black">
       <b>Current Status:</b> 
      </font>
    </p> 
   </div>
   <div class="right_box1">
    <font size="4.5" face="Times New Roman" color="black">
	 <br /> 
      <b> Going forward ...</b>
    </font>
   </div>	
   
   <!-- Control buttons -->
   <div class="Q_button" >
     <img border="0" src="qbutton.png" onclick = "displayQ()" 
	      alt="Q Button"  width="50" height="35" />
   </div>
   <div class="W_button">
     <img border="0" src="wbutton.png" onclick = "displayW()" 
	      alt="W Button"  width="50" height="35" />
   </div>
   <div class="E_button">
     <img border="0" src="ebutton.png" onclick = "displayE()"  
	      alt="E Button"  width="50" height="35" />
   </div>
   <div class="A_button">
     <img border="0" src="abutton.png" onclick = "displayA()"  
	      alt="A Button"  width="50" height="35" />
   </div>
   <div class="S_button">
     <img border="0" src="sbutton.png" onclick = "displayS()"  
	      alt="S Button"  width="50" height="35" />
   </div>
   <div class="D_button">
     <img border="0" src="dbutton.png" onclick = "displayD()"  
	      alt="D Button"  width="50" height="35" />
   </div>
   <div class="break_button">
     <img border="0" src="breakbutton.png" onclick = "displayBreak()"  
	      alt="break Button"  width="175" height ="42" />
   </div>
	
  </div> 
 </body>
</html>    