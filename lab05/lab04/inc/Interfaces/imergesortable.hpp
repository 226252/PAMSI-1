#ifndef IMERGESORTABLE_HPP
#define IMERGESORTABLE_HPP




  template <typename TYP>
  class imergesortable {
    
  public:

    imergesortable(){}
    virtual TYP& operator[](unsigned int indeks) const=0;
    virtual void reset()=0;
    // virtual void push_back(TYP value,unsigned short int option);
    virtual int get_last_index()=0;
    virtual void set_element(TYP what)=0;
    virtual ~imergesortable(){}
    virtual void add(TYP value)=0;
    
  };


#endif
