#ifndef MYTEST_H_INCLUDED
#define MYTEST_H_INCLUDED
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#define PTM_RATIO 20
#include<stdio.h>
class MyTest : public Test
{
public:
    MyTest()
    {
        b2FixtureDef groundBox;
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
        myBodyDef.position.Set(-10, 20); //a little to the left

        b2Body* dynamicBody1 = m_world->CreateBody(&myBodyDef);
        b2CircleShape circleShape;
        circleShape.m_p.Set(0, 0); //position, relative to body position
        circleShape.m_radius = 1; //radius
        b2FixtureDef myFixtureDef;
        myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
        dynamicBody1->CreateFixture(&myFixtureDef); //add a fixture to the body

        //set each vertex of polygon in an array
        b2Vec2 vertices[5];
        vertices[0].Set(-1,  2);
        vertices[1].Set(-1,  0);
        vertices[2].Set( 0, -3);
        vertices[3].Set( 1,  0.5);
        vertices[4].Set( 1,  1);
        b2FixtureDef myFixtureDef2;
        b2PolygonShape polygonShape;
        polygonShape.Set(vertices, 5); //pass array to the shape

        myFixtureDef.shape = &polygonShape; //change the shape of the fixture
        myBodyDef.position.Set(0, 20); //in the middle
        b2Body* dynamicBody2 = m_world->CreateBody(&myBodyDef);
        dynamicBody2->CreateFixture(&myFixtureDef); //add a fixture to the body




        b2Vec2 ver[50];

        for(int i=0;i<10;i++){
            ver[i].Set(cos(i*1.0/10*3.14)*2,sin(i*1.0/10*3.14)*2);
            printf("%lf %lf\n",ver[i].x,ver[i].y);
        }
        for(int i=0;i<10;i++){
            ver[19-i].Set(cos(i*1.0/10*3.14)*1.9,sin(i*1.0/10*3.14)*1.9);
            printf("%lf %lf\n",ver[i].x,ver[i].y);
        }
/*
        ver[0].Set(-1,0);


        ver[1].Set(-0.7,-0.7);

                ver[2].Set(0,-1);
                ver[3].Set(0,1);
                ver[4].Set(-0.7,0.7);
        */
        b2PolygonShape polygonShape2;
        printf("222\n");
        polygonShape2.Set(ver, 20); //pass array to the shape
        printf("111\n");
        myFixtureDef.shape = &polygonShape2; //change the shape of the fixture
        myBodyDef.position.Set(0, 40); //in the middle
        b2Body* dynamicBody3 = m_world->CreateBody(&myBodyDef);
        dynamicBody3->CreateFixture(&myFixtureDef); //add a fixture to the body


          myBodyDef.type = b2_staticBody; //change body type
  myBodyDef.position.Set(0,0); //middle, bottom

  polygonShape2.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) ); //ends of the line
  b2Body* staticBody = m_world->CreateBody(&myBodyDef);
  staticBody->CreateFixture(&myFixtureDef); //add a fixture to the body











    } //do nothing, no scene yet

    void Step(Settings* settings)
    {
        //run the default physics and rendering
        Test::Step(settings);

        //show some text in the main screen
        m_debugDraw.DrawString(5, m_textLine, "Now we have a foo test");
        m_textLine += 15;
    }

    static Test* Create()
    {
        return new MyTest;
    }
};

#endif // MYTEST_H_INCLUDED
