#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include "ray.hpp"

#ifndef CAMERA
#define CAMERA

class Camera {
  public:
                      Camera                ();
    void              initialize            ();

    int               resolutionWidth       () { return this->_resolutionWidth; }
    int               resolutionHeight      () { return this->_resolutionHeight; }

    void              updateResolution      (int, int);
    void              modelViewProjection   (const glm::mat4&) const;

    void              stepAlongGaze         (bool);
    void              verticalRotation      (int);
    void              horizontalRotation    (int);
    Ray               getRay                (int,int);

  private:
    void              updateView            ();
    void              updateProjection      ();

    float             _gazeStepSize;
    float             _verticalRotationAngle;
    float             _horizontalRotationAngle;

    glm::vec3         _gazePoint;
    glm::vec3         _toEyePoint;
    glm::vec3         _eyePoint;
    glm::vec3         _up;
    glm::vec3         _right;
    glm::mat4         _projection;
    glm::mat4         _view;
    int               _resolutionWidth;
    int               _resolutionHeight;
    float             _nearClipping;
    float             _farClipping;
};

#endif

