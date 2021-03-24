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


typedef struct tri{
    Vector3 A;
    Vector3 B;
    Vector3 C;

}Triangle;

typedef struct barycoords
{
  double alpha;
  double beta;
  double gamma;
}Barycoords;

Vector3 v3_sum(Vector3 v1, Vector3 v2);
Vector3 v3_dif(Vector3 v1, Vector3 v2);
Vector3 v3_dot(Vector3 v1, Vector3 v2);
Vector3 v3_cross(Vector3 v1, Vector3 v2);
Vector3 v3_norm(Vector3 v1);
double  v3_mod(Vector3 v1);
#endif