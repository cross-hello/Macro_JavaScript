### JavaScript macro definition enable 
Current program is for convert macro definiton use in JavaScript.
For example:
~~~C
#define doc document
#define get_id getElementById
#define get_class GetElementByClass
#define fun function
#define auto var
#nodef hi 
#define class doc.get_class
fun hi(){
auto i=doc.get_id('Hello');
auto b=class('Hi');
return i;
}
~~~
coule be convert to :

~~~JavasScript
#nodef hi 
function hi(){
var i=document.getElementById('Hello');
var b=document.GetElementByClass('Hi');
return i;
}
~~~

Support:
- single macro definition
- nested macro definition

Usage:
macro.exe wait_convert_file_name . . . wait_convert_file_name

Notice: You should write you file append .jc rear. Then the final resulat will be .js format. Otherwise the convert ccontent will be added to the original file.!  !  !  
