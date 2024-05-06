template <typename T,typename Vit> 
class Pair
{
    T x;
    Vit y;
    public:
      void setX(T x){
        this->x=x;
      }
      T getX(){
        return x;
      }
      void setY(Vit y){
        this->y=y;
      }
      Vit getY(){
        return y;
      }
};
