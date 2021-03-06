
#include <stdio.h>

int main(int argc, char **argv)
{
  int i, j, k, l;

  printf("; BEGIN cg4cpp\n");
  printf("; Visual Studio 2005 data type visualizers for Cg types provided by \"Cg for C++\"\n");
  printf("; Copyright 2008, NVIDIA Corporation\n");
  printf("; This section is AUTOMATICALLY GENERATED by generate_cg4cpp_autoexp.c -- DO NOT EDIT\n");
  printf("; Intended to be appended to the end of:\n");
  printf(";   C:\\Program Files\\Microsoft Visual Studio 8\\Common7\\Packages\\Debugger\\autoexp.dat\n");
  printf("[Visualizer]\n");
  printf("; Specialize float and double vectors to use more compact \"g\" format\n");
  printf("Cg::__CGvector<float,*>|Cg::__CGvector_plural<float,*>|Cg::__CGvector_storage<float,*,*> {\n");
  printf("  preview(  #array ( expr : [$c.x.v[$i],g], size : $T1 ) )\n");
  printf("}\n");
  printf("Cg::__CGvector_usage<float,*,*>|Cg::__CGvector_plural_usage<float,*,*> {\n");
  printf("  preview(  #array ( expr : [$c.v[$i],g], size : $T1 ) )\n");
  printf("}\n");
  printf("Cg::__CGswizzle<float,*,*,*>|Cg::__CGswizzle_storage<float,*,*,*> {\n");
  printf("  preview( #array ( expr : [$c.v[($T3 >> ($i*8)) & 0xFF],g], size : $T2 ) )\n");
  printf("}\n");
  printf("Cg::__CGvector<double,*>|Cg::__CGvector_plural<double,*>|Cg::__CGvector_storage<double,*,*> {\n");
  printf("  preview(  #array ( expr : [$c.x.v[$i],g], size : $T1 ) )\n");
  printf("}\n");
  printf("Cg::__CGvector_usage<double,*,*>|Cg::__CGvector_plural_usage<double,*,*> {\n");
  printf("  preview(  #array ( expr : [$c.v[$i],g], size : $T1 ) )\n");
  printf("}\n");
  printf("Cg::__CGswizzle<double,*,*,*>|Cg::__CGswizzle_storage<double,*,*,*> {\n");
  printf("  preview( #array ( expr : [$c.v[($T3 >> ($i*8)) & 0xFF],g], size : $T2 ) )\n");
  printf("}\n");
  printf("Cg::__CGvector<*,*>|Cg::__CGvector_plural<*,*>|Cg::__CGvector_storage<*,*,*> {\n");
  printf("  preview(  #array ( expr : $c.x.v[$i], size : $T2 ) )\n");
  printf("}\n");
  printf("Cg::__CGvector_usage<*,*,*>|Cg::__CGvector_plural_usage<*,*,*> {\n");
  printf("  preview(  #array ( expr : $c.v[$i], size : $T2 ) )\n");
  printf("}\n");
  printf("Cg::__CGswizzle<*,*,*,*>|Cg::__CGswizzle_storage<*,*,*,*> {\n");
  printf("  preview( #array ( expr : $c.v[($T4 >> ($i*8)) & 0xFF], size : $T3 ) )\n");
  printf("}\n");

  for (i=1; i<=4; i++) {
    for (j=1; j<=4; j++) {
      printf("Cg::__CGmatrix<*,%d,%d,*> {\n", i, j);
      printf("  preview( #( $e.");
      for (k=0; k<j; k++) {
        printf("_1%c", "1234"[k]);
      }
      for (k=1; k<i; k++) {
        printf(", \"; \", $e.");
        for (l=0; l<j; l++) {
          printf("_%c%c", "1234"[k], "1234"[l]);
        }
      }
      printf(" ) )\n");
      printf("}\n");
    }
  }

  printf("; Convert s10e5 16-bit float representation into equivalent print-able float\n");
  printf("Cg::__CGcustom_float<10,5,1,0>|Cg::__CGcustom_float_storage<10,5,1> {\n");
  printf("  preview(\n");
  printf("    ; switch on 5-bit exponent\n");
  printf("    #switch(($c.v[1] >> 2) & 0x1f)\n");
  printf("    #case 0 (\n");
  printf("      ; denorm case so no leading one\n");
  printf("      [(float)((((($c.v[0]) | ($c.v[1] << 8)) & 0x3ff)*(1-2*($c.v[1] >> 7))) * 0.000000059604644775390625),g]\n");
  printf("    )\n");
  for (i=1; i<31; i++) {
    double scale = (i > 25) ? (1<<(i-25)) : 1.0/(1<<(25-i));
    int v;

    if (i > 25) {
      v = i - 25;
      scale = 1<<v;
    } else {
      v = -(i - 25);
      scale = 1.0 / (1<<v);
    }
    printf("    #case %d (\n", i);
    printf("      [(float)(((0x400 | ((($c.v[0]) | ($c.v[1] << 8)) & 0x3ff))*(1-2*($c.v[1] >> 7))) * %.24f),g]\n", scale);
    printf("    )\n");
  }
  printf("    ; infinity and not-a-number cases\n");
  printf("    #case 31 (\n");
  printf("      #if ((($c.v[0]) | ($c.v[1] << 8)) & 0x3ff) (\n");
  printf("        #if ($c.v[1] & 0x80) (\n");
  printf("          \"-NaN\"\n");
  printf("        ) #else (\n");
  printf("          \"+NaN\"\n");
  printf("        )\n");
  printf("      ) #else (\n");
  printf("        #if ($c.v[1] & 0x80) (\n");
  printf("          \"-Inf\"\n");
  printf("        ) #else (\n");
  printf("          \"+Inf\"\n");
  printf("        )\n");
  printf("      )\n");
  printf("    )\n");
  printf("  )\n");
  printf("}\n");
  printf("; Convert s1.10 8-bit fixed-point representation into equivalent print-able float\n");
  printf("Cg::__CGcustom_fixed<1,10,1>|Cg::__CGcustom_fixed_storage<1,10,1> {\n");
  printf("  preview(\n");
  printf("    [(((($c.v[0]) | ($c.v[1] << 8)) << 20) >> 20) / 1024.0,g]\n");
  printf("  )\n");
  printf("}\n");
  printf("; Convert u0.8 8-bit fixed-point representation into equivalent print-able float\n");
  printf("Cg::__CGcustom_fixed<0,8,0>|Cg::__CGcustom_fixed_storage<0,8,0> {\n");
  printf("  preview(\n");
  printf("    [$c.v[0] / 255.0,g]\n");
  printf("  )\n");
  printf("}\n");
  printf("Cg::__CGwrap_type<*>|Cg::InOut<*>|Cg::In<*>|Cg::Out<*> {\n");
  printf("  preview(\n");
  printf("    *(($T1 *)&($c))\n");
  printf("  )\n");
  printf("}\n");
  printf("; END cg4cpp\n");
  exit(0);
}
