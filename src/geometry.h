#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct vec2
{
  double x;
  double y;
}Vector2;

typedef struct vec3
{
    double x;
    double y;
    double z;
}Vector3;

//for omogeneous coordinates
typedef struct vec4
{
    double x;
    double y;
    double z;
    double w;
}Vector4;


typedef struct tri3{
    Vector3 A;
    Vector3 B;
    Vector3 C;

}Triangle3;

typedef struct tri2{
    Vector2 A;
    Vector2 B;
    Vector2 C;

}Triangle2;

typedef struct barycoords
{
  double alpha;
  double beta;
  double gamma;
}Barycoords;

Vector3 v3_sum(Vector3 v1, Vector3 v2);
Vector3 v3_dif(Vector3 v1, Vector3 v2);
double  v3_dot(Vector3 v1, Vector3 v2);
Vector3 v3_cross(Vector3 v1, Vector3 v2);
Vector3 v3_norm(Vector3 v1);
double  v3_mod(Vector3 v1);

Vector2 v2_sum(Vector2 v1, Vector2 v2);
Vector2 v2_dif(Vector2 v1, Vector2 v2);
double  v2_dot(Vector2 v1, Vector2 v2);
Vector3 v2_cross(Vector2 v1, Vector2 v2);
Vector2 v2_norm(Vector2 v1);
double  v2_mod(Vector2 v1);


#endif