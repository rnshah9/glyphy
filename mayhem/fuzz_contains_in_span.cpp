#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>
#include "glyphy-geometry.hh"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    double a = provider.ConsumeFloatingPoint<double>();
    double b = provider.ConsumeFloatingPoint<double>();
    double c = provider.ConsumeFloatingPoint<double>();
    double d = provider.ConsumeFloatingPoint<double>();
    double e = provider.ConsumeFloatingPoint<double>();
    double f = provider.ConsumeFloatingPoint<double>();
    GLyphy::Geometry::Point p1(a, b);
    GLyphy::Geometry::Point p2(c, d);
    GLyphy::Geometry::Point p3(e, f);
    GLyphy::Geometry::Segment seg(p1, p2);

    seg.contains_in_span(p3);

    return 0;
}
