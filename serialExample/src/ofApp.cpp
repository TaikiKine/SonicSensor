#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	ofBackground(255);	
		
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	int baud = 57600;
    serial.setup(0, baud);
    
    result = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
   
    serial.writeByte('a');
    
    if (serial.available() > 0) {
        
        int highByte = serial.readByte();
        int lowByte = serial.readByte();
        if (highByte == OF_SERIAL_ERROR || lowByte == OF_SERIAL_ERROR);
        else if (lowByte == OF_SERIAL_NO_DATA || lowByte == OF_SERIAL_NO_DATA);
        else result =  (highByte<<8) + lowByte;
        
        cout << result << endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	
}

