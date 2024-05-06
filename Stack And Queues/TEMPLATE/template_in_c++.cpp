// making a template of class pair
// template <typename T>  // for same data type member class
template <typename T,typename Vit>  // for 2 data type members class
// and aise hi we can make template for n data type member class
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
