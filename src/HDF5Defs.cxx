#include "HDF5Defs.hh"
#include "HDF5Writer.hh"

namespace h5 {

  template<>
  H5::DataType get_type<Track>() {
    H5::CompType type(sizeof(Track));
#define INSERT(name) H5_INSERT(type, Track, name)
    INSERT(pt);
    INSERT(mask);
#undef INSERT
    return type;
  }

  template<>
  Track get_empty<Track>() {
    Track cl;
    cl.pt = 0;
    cl.mask = false;
    return cl;
  }

}
