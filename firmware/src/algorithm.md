# Algorithm 1 
'''
unsigned int num-1,num-2 ;
num-1 = num-2 = 0;
char state = 0; // num-1 first 
char keypad ; // input keypad 
char check = -3; // 3/3 input
char value =-1; 
LOOP:
do value = keypad(); 
while ( value == -1 )

// Check value 
switch value:
case [#button]:
  state = !state; 
case [ABCD]:
  led_matrix(); 
  update(operator); 
  check++;
case [*button]:
  check if result <= 9999 && check >=0:
    state = 2;
    led_out();
case [0123456789]:
  if (state == 0):
    num-1 = (num-1 * 10 + value)%10.000;
    check++;
    led_out();
  if (state == 1):
    num-2 = (num-2 * 10 + value)%10.000;
    led_out();
    check++;
Goto LOOP;
'''
