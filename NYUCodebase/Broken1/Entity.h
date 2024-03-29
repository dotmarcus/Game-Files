//
//  Entity.h
//  NYUCodebase
//
//  Created by Marcus Williams on 4/14/15.
//  Copyright (c) 2015 Ivan Safrin. All rights reserved.
//

#ifndef NYUCodebase_Entity_h
#define NYUCodebase_Entity_h

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "NewSpriteSheet.h"
#include <string>


class Entity {
public:
    Entity () : x(0.0), y(0.0), width(0.0), height(0.0), rotation(0.0), velocity_x (0.0), velocity_y(0.0), acceleration_x(0.0), acceleration_y(0.0), friction_x(0.0), friction_y(0.0), mass(1.0), direction_x(0.0), direction_y(0.0), framesPerSecond(0.0), gravity_x(0.0), gravity_y(0.0), spriteSheetTexture(0), sprite(spriteSheetTexture, x, y, 0.0, 0.0, width, height) {}
    
    void Update(float elapsed);
    void Render(float elapsed);
    
    void DrawSprite(int spriteTexture, int index, int spriteCountX, int spriteCountY);
    bool collidesWith(Entity entity);
//    bool checkBottomCollison();
    bool isCollision(Entity entity);
    
    void FixedUpdate();
//    bool FixedUpdate(Entity other);
    SheetSprite sprite;
    void Jump();
    
    float x;
    float y;
    
    float width;
    float height;
    float rotation;
    
    float direction_x;
    float direction_y;
    
    float velocity_x;
    float velocity_y;
    
    float acceleration_x;
    float acceleration_y;
    
    float friction_x;
    float friction_y;
    
    float gravity_x;
    float gravity_y;
    
    bool movingRight;
    bool movingLeft;
    
    float mass;
    bool isStatic;
    
    bool enableCollisions;
    
    bool collidedTop;
    bool collidedBottom;
    bool collidedLeft;
    bool collidedRight;
    
    float animationElapsed = 0.0f;
    float framesPerSecond;
    int currentIndex = 0;
    float offset;
    float penetration;
    int charge = 0;
    std::string type;
    float scale;
    float numFrames;
    int idx = 0;
    int fixed = 8;
    unsigned int spriteSheetTexture;
    
    float rightEdge;
    float leftEdge;
    float topEdge;
    float bottomEdge;
};


GLuint LoadTexture(const char *image_path);
float lerp(float v0, float v1, float t);
float mapValue(float value, float srcMin, float srcMax, float dstMin, float dstMax);
float easeOut(float from, float to, float time);

#endif
