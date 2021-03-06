
#pragma once
#include "ofMain.h"
#include "ofxBox2dBaseShape.h"
#include "ofxBox2dPolygonUtils.h"

class ofxBox2dPolygon : public ofxBox2dBaseShape, public ofPolyline {

private:
	
	bool	bIsSimplified;
	bool    bIsTriangulated;
	float   area;
	ofVec2f center;
	void    calculateCentroid();
	float   calculateArea();
    void    makeConvexPoly();

public:
	
	ofVboMesh				mesh;
	ofRectangle				bounds;
	std::vector<TriangleShape>	triangles;
	
	//----------------------------------------
	ofxBox2dPolygon();
	~ofxBox2dPolygon();
	void destroy();
	void clear();
    
	//----------------------------------------
	void addTriangle(const ofDefaultVertexType &a, const ofDefaultVertexType &b, const ofDefaultVertexType &c);

    OF_DEPRECATED_MSG("Use addVertices instead.", void addVertexes(std::vector<ofDefaultVertexType> &pts) );
    OF_DEPRECATED_MSG("Use addVertices instead.", void addVertexes(ofPolyline &polyline) );

    void addVertices(const std::vector<ofDefaultVertexType>& pts);
    void addVertices(const ofPolyline &polyline);

	//----------------------------------------
	// Polygon helper functions
	//----------------------------------------
	void simplify(float tolerance=0.3);
    void simplifyToMaxVerts();
	void triangulatePoly(float resampleAmt=20, int nPointsInside=-1);
    
	//----------------------------------------
	std::vector<ofDefaultVertexType> &getPoints();
	bool	isGoodShape() { return calculateArea() > 15; }
    
	//------------------------------------------------
	void addAttractionPoint(ofVec2f pt, float amt=1);
	void addAttractionPoint(float x, float y, float amt=1);
	void addRepulsionForce(float x, float y, float amt);
	void addRepulsionForce(ofVec2f pt, float amt);

	//----------------------------------------
	void create(b2World * b2dworld);
	void draw();
	
};
