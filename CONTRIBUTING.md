## Style Preferences:
The style is similar to K&R, with a few key differences:
`/* every comment is done in blocks */`
and indents are two *spaces.* The horizontal character limit is 80, which is ISO standard. Spaces are used graciously.
Objects are declared on their own lines, primitive types can be done in groups. Functions are done in C style, *not* in 
Java's satanist camelcase. I'm not even sure why I myself have adopted this standard, but all functions involving rotation 
use british conventional spelling over American (so anticlockwise instead of counterclockwise.)
A function will look similar to this:
```cpp
int x,y;
Robot* robot = new Robot( );
/*
 * Takes params x, y, and if x dne 0, does the thing with y, 
 * otherwise, the robots kill us all.
 */
void foobar( int x, int y ){
  while( x != 0 ){
    do_thing( y );
  }
  else {
    /* Set the robot to the proper mode */
    robot -> kill( humans );
  }
}
void anticlockwise( int pwm ){
  . . . 
  
}
```
