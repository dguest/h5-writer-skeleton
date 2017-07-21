#include "HDF5Writer.hh"
#include "HDF5Defs.hh"
#include "Track.hh"
#include <cstdio>
#include <cstdlib>
int main(int argc, char* argv[]) {
  int in = 0;
  if (argc > 1) in = atoi(argv[1]);

  H5::H5File out_file("test.h5", H5F_ACC_TRUNC);
  h5::Writer<Track> track_writer(out_file, "tracks", in, 256);

  std::vector<Track> test_tracks(in);
  for (int iii = 0; iii < in; iii++) {
    track_writer.add(test_tracks);
  }
  track_writer.flush();
  track_writer.close();

  return 0;
}
