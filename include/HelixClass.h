#ifndef HELIXAR_H
#define HELIXAR_H 1

/**
 *    Utility class to manipulate with different parameterisations <br>
 *    of helix. Helix can be initialized in a three different <br>
 *    ways using the following public methods : <br>
 *    1) Initialize_VP(float * pos, float * mom, float q, float B) : <br>
 *       initialization of helix is done using <br>
 *       - position of the reference point : pos[3]; <br>
 *       - momentum vector at the reference point : mom[3];<br>
 *       - particle charge : q;<br>
 *       - magnetic field (in Tesla) : B;<br>
 *    2) Initialize_BZ(float xCentre, float yCentre, float radius, <br>
 *				   float bZ, float phi0, float B, float signPz,<br>
 *				   float zBegin):<br>
 *       initialization of helix is done according to the following<br>
 *       parameterization<br>
 *       x = xCentre + radius*cos(bZ*z + phi0)<br>
 *       y = yCentre + radius*sin(bZ*z + phi0)<br>
 *       where (x,y,z) - position of point on the helix<br>
 *       - (xCentre,yCentre) is the centre of circumference in R-Phi plane<br>
 *       - radius is the radius of circumference<br>
 *       - bZ is the helix slope parameter<br>
 *       - phi0 is the initial phase of circumference<br>
 *       - B is the magnetic field (in Tesla)<br>
 *       - signPz is the sign of the z component of momentum vector<br>
 *       - zBegin is the z coordinate of the reference point;<br>
 *    3) void Initialize_Canonical(float phi0, float d0, float z0, float omega,<br> 
 *			      float tanlambda, float B) :<br>
 *    canonical (LEP-wise) parameterisation with the following parameters<br>
 *       - phi0 - Phi angle of momentum vector at the point of<br>
 *         closest approach to IP in R-Phi plane;
 *       - d0 - signed distance of closest approach to IP in R-Phi plane;<br>
 *       - z0 - z coordinate of the point of closest approach in R-Phi plane;<br>
 *       - omega - signed curvature;<br>
 *       - tanlambda - tangent of dip angle;<br>
 *       - B - magnetic field (in Tesla);<br>
 *    A set of public methods (getters) provide access to <br>
 *    various parameters associated with helix. Helix Class contains<br>
 *    also several utility methods, allowing for calculation of helix<br>
 *    intersection points with planes parallel and perpendicular to <br>
 *    z (beam) axis and determination of the distance of closest approach<br>
 *    from arbitrary 3D point to the helix. <br>
 *    @author A. Raspereza (DESY)<br>
 *    @version $Id: HelixClass.h,v 1.12 2006-11-02 12:21:07 rasp Exp $<br>
 *
 */

#include "LineClass.h"
class HelixClass;

class HelixClass {
 public:

/**
 *  Constructor. Initializations of constants which are used
 *  to calculate various parameters associated with helix.
 */ 
    HelixClass();
/**
 *  Destructor. 
 */
    ~HelixClass();
/**
 *   Initialization of helix using <br>
 *     - position of the reference point : pos[3]; <br>
 *     - momentum vector at the reference point : mom[3];<br>
 *     - particle charge : q;<br>
 *     - magnetic field (in Tesla) : B<br>
 */  
    void Initialize_VP(float * pos, float * mom, float q, float B);

/**
 *   Initialization of helix according to the following<br>
 *   parameterization<br>
 *   x = xCentre + radius*cos(bZ*z + phi0)<br>
 *   y = yCentre + radius*sin(bZ*z + phi0)<br>
 *     where (x,y,z) - position of point on the helix<br>
 *     - (xCentre,yCentre) is the centre of circumference in R-Phi plane<br>
 *     - radius is the radius of circumference<br>
 *     - bZ is the helix slope parameter<br>
 *     - phi0 is the initial phase of circumference<br>
 *     - B is the magnetic field (in Tesla)<br>
 *     - signPz is the sign of the z component of momentum vector<br>
 *     - zBegin is the z coordinate of the reference point<br>
 */  
    void Initialize_BZ(float xCentre, float yCentre, float radius, 
				   float bZ, float phi0, float B, float signPz,
				   float zBegin);
/**
 *  Canonical (LEP-wise) parameterisation with the following parameters<br>
 *     - phi0 - Phi angle of momentum vector at the point of<br>
 *       closest approach to IP in R-Phi plane;
 *     - d0 - signed distance of closest approach in R-Phi plane;<br>
 *     - z0 - z coordinate of the point of closest approach to IP 
 *       in R-Phi plane;<br>
 *     - omega - signed curvature;<br>
 *     - tanlambda - tangent of dip angle;<br>
 *     - B - magnetic field (in Tesla)<br>
 */  
    void Initialize_Canonical(float phi0, float d0, float z0, float omega, 
			      float tanlambda, float B);
    /**
     *  Returns momentum of particle at the point of closest approach <br>
     *  to IP <br>
     */
    const float * getMomentum();

    /**
     *  Returns reference point of track <br>     
     */
    const float * getReferencePoint();

    /**
     *  Returns Phi angle of the momentum vector <br>
     *  at the point of closest approach to IP <br>     
     */
    float getPhi0();

    /**
     *  Returns signed distance of closest approach <br>
     *  to IP in the R-Phi plane <br>     
     */
    float getD0();

    /**
     *  Returns z coordinate of the point of closest 
     *  approach to IP in the R-Phi plane <br>     
     */
    float getZ0();

    /**
     *  Returns signed curvature of the track <br>     
     */
    float getOmega();

    /**
     *  Returns tangent of dip angle of the track <br>     
     */
    float getTanLambda();

    /**
     *  Returns transverse momentum of the track <br>     
     */
    float getPXY();


    /**
     *  Returns x coordinate of circumference
     */
    float getXC();

    /**
     *  Returns y coordinate of circumference
     */
    float getYC();


     /**
     *  Returns radius of circumference
     */
    float getRadius();   


    /**
     *  Returns helix intersection point with the plane <br>
     *  parallel to z axis. Plane is defined by two coordinates <br>
     *  of the point belonging to the plane (x0,y0) and normal <br>
     *  vector (ax,ay).  ref[3] is the reference point of the helix. <br>
     *  point[3] - returned vector holding the coordinates of <br>
     *  intersection point <br>     
     */
    float getPointInXY(float x0, float y0, float ax, float ay, 
			      float * ref , float * point);

    /**
     *  Returns helix intersection point with the plane <br>
     *  perpendicular to z axis. Plane is defined by z coordinate <br>
     *  of the plane. ref[3] is the reference point of the helix. <br>
     *  point[3] - returned vector holding the coordinates of <br>
     *  intersection point <br>     
     */
    float getPointInZ(float zLine, float * ref, float * point);

    /**
     * Return distance of the closest approach of the helix to <br>
     * arbitrary 3D point in space. xPoint[3] - coordinates of <br>
     * space point. Distance[3] - vector of distances of helix to <br> 
     * a given point in various projections : <br>
     * Distance[0] - distance in R-Phi plane <br>
     * Distance[1] - distance along Z axis <br>
     * Distance[2] - 3D distance <br> 
     */
    float getDistanceToPoint(float * xPoint, float * Distance);

    /**
     * This method calculates coordinates of helix intersection <br>
     * with cyllinder. <br>
     * Rotational symmetry with respect to z axis is assumed,  <br>
     * meaning that cyllinder axis corresponds to the z axis <br>
     * of reference frame. <br>
     * Inputs : <br> 
     * Radius - radius of cyllinder. <br>
     * ref[3] - reference point on the helix. <br>
     * Output : <br>
     * point[3] - coordinates of intersection point. <br>
     * Method returs also generic time, defined as the <br>
     * ratio of helix length from reference point to the intersection <br>
     * point to the particle momentum <br>
     */
    float getPointOnCircle(float Radius, float * ref, float * point);

    /** Returns distance between two helixes <br>
     * Output : <br> 
     * pos[3] - position of the point of closest approach <br>
     * mom[3] - momentum of V0 <br>
     */
    float * getDistanceToHelix(HelixClass * helix, float * pos, float * mom);

    /**
     * Returns distance to Line.
     */
    float getDistanceToLine(LineClass * line);

    /**
     * Set Edges of helix 
     */
    void setHelixEdges(float * xStart, float * xEnd);

    /**
     * Returns starting point of helix
     */
    float * getStartingPoint() {return _xStart;}

    /**
     * Returns endpoint of helix
     */
    float * getEndPoint() {return _xEnd;}
    
    /**
     * Returns BZ for the second parameterization
     */
    float getBz();

    /**
     * Returns Phi for the second parameterization
     */
    float getPhiZ();

    /**
     * Returns extrapolated momentum
     */
    void getExtrapolatedMomentum(float * pos, float * momentum);

    /**
     * Returns charge 
     */
    float getCharge();


 private:    
    float _momentum[3]; // momentum @ ref point 
    float _referencePoint[3]; // coordinates @ ref point
    float _phi0; // phi0 in canonical parameterization 
    float _d0;   // d0 in canonical parameterisation
    float _z0;   // z0 in canonical parameterisation
    float _omega; // signed curvuture in canonical parameterisation
    float _tanLambda; // TanLambda 
    float _pxy; // Transverse momentum
    float _charge; // Particle Charge
    float _bField; // Magnetic field (assumed to point to Z>0)
    float _radius; // radius of circle in XY plane
    float _xCentre; // X of circle centre
    float _yCentre; // Y of circle centre
    float _phiRefPoint; // Phi w.r.t. (X0,Y0) of circle @ ref point
    float _phiAtPCA; // Phi w.r.t. (X0,Y0) of circle @ PCA 
    float _xAtPCA; // X @ PCA
    float _yAtPCA; // Y @ PCA
    float _pxAtPCA; // PX @ PCA
    float _pyAtPCA; // PY @ PCA
    float _phiMomRefPoint; // Phi of Momentum vector @ ref point
    float _const_pi; // PI
    float _const_2pi; // 2*PI
    float _const_pi2; // PI/2    
    float _FCT; // 2.99792458E-4
    float _xStart[3]; // Starting point of track segment
    float _xEnd[3]; // Ending point of track segment

    float _bZ;
    float _phiZ;

};


#endif
