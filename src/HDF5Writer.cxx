#include "HDF5Writer.hh"

#include "H5Cpp.h"

namespace h5 {

  // template specializations
  template<>
  H5::DataType get_type<float>() {
    return H5::PredType::NATIVE_FLOAT;
  }
  template<>
  H5::DataType get_type<double>() {
    return H5::PredType::NATIVE_DOUBLE;
  }
  template<>
  H5::DataType get_type<int>() {
    return H5::PredType::NATIVE_INT;
  }
  template<>
  H5::DataType get_type<bool>() {
    bool TRUE = true;
    bool FALSE = false;
    H5::EnumType btype(sizeof(bool));
    btype.insert("TRUE", &TRUE);
    btype.insert("FALSE", &FALSE);
    return btype;
  }


  // packing utility
  H5::DataType packed(H5::DataType in) {
    // TODO: Figure out why a normal copy constructor doesn't work here.
    //       The normal one seems to create shallow copies.
    auto out = H5::CompType(H5Tcopy(in.getId()));
    out.pack();
    return out;
  }

}
