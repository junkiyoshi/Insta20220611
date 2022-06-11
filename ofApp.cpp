#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_SUBTRACT);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	for (float radius = 20; radius <= 290; radius += 90) {

		for (float hue = 0; hue < 256; hue += 8) {

			color.setHsb(hue, 200, 255);
			ofSetColor(color);

			ofBeginShape();
			for (float deg = 0; deg < 360; deg += 1) {

				auto base_location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
				auto tmp_radius = ofMap(ofNoise(base_location.x * 0.05, base_location.y * 0.05, hue * 0.0015, ofGetFrameNum() * 0.005), 0, 1, radius * 0.8, radius * 1.3);
				ofVertex(tmp_radius * cos(deg * DEG_TO_RAD), tmp_radius * sin(deg * DEG_TO_RAD));
			}
			ofEndShape(true);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}