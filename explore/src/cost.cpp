
//////////// a partir de la linea 175///////////////////

for (auto& frontier : frontier_list) {
    frontier.cost = myfrontierCost(frontier);
  }


///////////de la línea 331 al final/////////////////////
//NOTE min_distance es la distancia a la frontera más cercana.
//potential y gain son constantes y la resolución vamos a suponer que también
//El original hace una escala de la que tenga a otra muy cerca y encima sea 
//de tamaño pequeño

//Con el que hemos creado queremos que priorice también las fronteras más cercanas
double FrontierSearch::myfrontierCost(const Frontier& frontier)
{
  Costmap2DClient costmap_client_;
  auto pose = costmap_client_.getRobotPose();
  auto fpoint = frontier.inital();
  float dist = sqrt((pose.x - fpoint.x) * (pose.x - fpoint.x) +
                     (pose.y - fpoint.y) * (pose.y - fpoint.y));
  return (3 * dist * costmap_->getResolution()) + (potential_scale_ * frontier.min_distance *
          costmap_->getResolution()) -
         (gain_scale_ * frontier.size * costmap_->getResolution());
}
//NOTE