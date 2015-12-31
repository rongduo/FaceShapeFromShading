#ifndef FACESHAPEFROMSHADING_OFFSCREENMESHVISUALIZER_H
#define FACESHAPEFROMSHADING_OFFSCREENMESHVISUALIZER_H

#include "Geometry/geometryutils.hpp"
#include "Utils/utility.hpp"

#include <MultilinearReconstruction/basicmesh.h>
#include <MultilinearReconstruction/parameters.h>

#include <QImage>
#include <QOpenGLContext>
#include <QOpenGLFramebufferObject>
#include <QOffscreenSurface>

#include <boost/timer/timer.hpp>

class OffscreenMeshVisualizer {
public:
  enum MVPMode {
    OrthoNormal,
    CamPerspective
  };
  OffscreenMeshVisualizer(int width, int height) : width(width), height(height) {}

  void BindMesh(const BasicMesh& in_mesh) {
    mesh = in_mesh;
  }
  void SetMeshRotationTranslation(const Vector3d& R, const Vector3d& T) {
    mesh_rotation = R;
    mesh_translation = T;
  }
  void SetCameraParameters(const CameraParameters& cam_params) {
    camera_params = cam_params;
  }

  void SetMVPMode(MVPMode mode_in) {
    mode = mode_in;
  }

  QImage Render() const;

protected:
  void SetupViewing() const;

private:
  int width, height;
  MVPMode mode;

  Vector3d mesh_rotation, mesh_translation;
  CameraParameters camera_params;

  BasicMesh mesh;
};


#endif //FACESHAPEFROMSHADING_OFFSCREENMESHVISUALIZER_H