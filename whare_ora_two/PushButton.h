//#include <Bounce2.h>
//#include <MySensor.h>
//Bounce debouncer = Bounce(); 
//int oldValue=-1;
//
//void setupButton() {
//   // Setup the button
//  pinMode(PUSHBUTTON_PIN,INPUT);
//  // Activate internal pull-up
//  digitalWrite(PUSHBUTTON_PIN,HIGH);
//  // After setting up the button, setup debouncer
//  debouncer.attach(PUSHBUTTON_PIN);
//  debouncer.interval(5);
//}
//
//
//void checkButton(MySensor gw) {
//    debouncer.update();
//  // Get the update value
//  int value = debouncer.read();
// 
//  if (value != oldValue) {
//     // Send in the new value
//     gw.send(msg.set(value==HIGH ? 1 : 0));
//     oldValue = value;
//  }
//}

