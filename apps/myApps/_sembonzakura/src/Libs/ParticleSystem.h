//
//  ParticleSystem.h
//  asobu
//
//  Created by NAMBU AKIFUMI on 2015/10/31.
//
//

#ifndef asobu_ParticleSystem_h
#define asobu_ParticleSystem_h

template<typename Particle>
class ParticleSystem {
    vector<Particle> particles;
    
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f acc;
    
    float rotDegree;
    ofVec3f rotAxis;
    float rotSpeed;
    
    ofVec3f attractPoint;
    float attractPower;
    ofVec3f gravity;
    
    
    
public:
    
    void setPosition(float x, float y){pos=ofVec3f(x, y);};
    void setPosition(float x, float y, float z){pos=ofVec3f(x,y,z);};
    void setPosition(ofPoint pos){this->pos = pos;};
    void setVelocity(float x, float y){vel=ofVec3f(x,y);};
    void setVelocity(float x, float y, float z){vel=ofVec3f(x,y,z);};
    void setVelocity(ofPoint vel){this->vel=vel;};
    void setAccelerator(float x, float y){acc=ofVec3f(x,y);};
    void setAccelerator(float x, float y, float z){acc=ofVec3f(x,y,z);};
    void setAccelerator(ofPoint acc){this->acc = acc;};
    void setRotDegree(float degree){this->rotDegree = degree;};
    void setRotSpeed(float rotateSpeed){this->rotSpeed = rotateSpeed;};
    void setRotAxis(float x, float y, float z){rotAxis=ofVec3f(x,y,z);};
    void setRotAxis(ofPoint rotAxis){this->rotAxis = rotAxis;};
    void setAttractPoint(float x, float y){attractPoint=ofVec3f(x,y);};
    void setAttractPoint(float x, float y, float z){attractPoint=ofVec3f(x,y,z);};
    void setAttractPoint(ofPoint attractPoint){this->attractPoint = attractPoint;};
    void setAttractPower(float attractPower){this->attractPower = attractPower;};
    
    void setGravity(float x, float y){gravity=ofVec3f(x,y);};
    void setGravity(float x, float y, float z){gravity=ofVec3f(x,y,z);};
    void setGravity(ofPoint gravity){this->gravity = gravity;};
    
    ParticleSystem<Particle>(){
        pos = ofVec3f(0,0,0);
        vel = ofVec3f(0,0,0);
        acc = ofVec3f(0,0,0);
        rotAxis = ofVec3f(1,0,0);
        attractPoint = ofVec3f(0,0,0);
        gravity = ofVec3f(0,0,0);
        
        rotDegree = 0;
        rotSpeed = 0;
        attractPower = 0;
    }
    
    void update(){
        vel += gravity;
        ofVec3f attractAcc = attractPoint - pos;
        vel += attractPower * attractAcc.normalize() / attractAcc.length() / attractAcc.length();
        pos += vel;
        
        rotDegree += rotSpeed;
        
        for (typename vector<Particle>::iterator it = particles.begin(); it != particles.end(); ++it) {
            it -> update();
        }
        
        for (typename vector<Particle>::iterator it = particles.begin(); it != particles.end(); ++it) {
            if(it -> isDead()){
                particles.erase(it);
                --it;
            }
        }
    }
    
    void draw(){
        ofPushMatrix();
        for (typename vector<Particle>::iterator it = particles.begin(); it != particles.end(); ++it) {
            it -> draw();
        }
        ofPopMatrix();
    }
    
    void addParticle(Particle particle){
        particle.setPosition(pos);
        particles.push_back(particle);
    }
    
    bool isDead(){
        return particles.count() == 0;
    }
    
};

#endif
