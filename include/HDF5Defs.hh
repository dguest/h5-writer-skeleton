#ifndef HDF5_DEFS_HH
#define HDF5_DEFS_HH

#include "Track.hh"
#include "HDF5Writer.hh"

#include <string>

namespace h5 {
  template<> H5::DataType get_type<Track>();
  template<> Track get_empty<Track>();
}

#endif
