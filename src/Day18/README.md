# Assignments

## Implement a Vector template class

Implement a bsic vector template class. The outline is described below. Note that the class will not compile as it's just pseudo code for the outline.

```
template<typename T>
class Vector {
private:
    T* mData; // this is the actual data (or array)
	  int mSize; // Size is how much data.  Capacity is how much memory.
	  int mCapacity; // not always same as mSize, usually much larger than mSize.
	  T mUndefined;// Lots of STL functions say that doing something naughty gets "undefined behavior".
public:
    Vector() {
		    mSize = 0;
        mCapacity = 0;
		    mData = NULL;
		    Reserve( 15 ); // If you put a new in here, you'd be duplicating the reserve code.
	  }
	  ~Vector() { }
	  Vector( const Vector<T>& tOther ) : Vector() { }
	  Vector& operator =( const Vector<T>& tRHS ) { }
	  void PushBack( const T& tItem ) { }
	  void PopBack() { }
	  T& At( int tWhere ) { }
	  void Clear() { mSize = 0; }
	  int Size() const { return mSize; }
	  void Reserve( int tCount ) { } // use an algorithm to increase capacity as required
	  int Capacity() const { return mCapacity; }
};
```
