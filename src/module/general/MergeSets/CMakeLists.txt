
SET(HEADERS
  
)

SET(SOURCES
  MergeSets.cpp
)

SET(EXTRASOURCES
  MergeSets.h
)

ADD_COVISE_MODULE(Tools MergeSets ${EXTRASOURCES} )
TARGET_LINK_LIBRARIES(MergeSets  coApi coAppl coCore )

COVISE_INSTALL_TARGET(MergeSets)
