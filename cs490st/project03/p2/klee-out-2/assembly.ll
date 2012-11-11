; ModuleID = 'klee_stopper.o'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32"
target triple = "i386-pc-linux-gnu"

@.str = private constant [36 x i8] c"KLEE should not be able to get here\00", align 4 ; <[36 x i8]*> [#uses=1]
@.str1 = private constant [23 x i8] c"KLEE is not very smart\00", align 1 ; <[23 x i8]*> [#uses=1]

define i32 @main(i32 %argc, i8** %argv) nounwind {
entry:
  %argc_addr = alloca i32                         ; <i32*> [#uses=1]
  %argv_addr = alloca i8**                        ; <i8***> [#uses=1]
  %retval = alloca i32                            ; <i32*> [#uses=2]
  %0 = alloca i32                                 ; <i32*> [#uses=2]
  %a = alloca double, align 8                     ; <double*> [#uses=3]
  %b = alloca double, align 8                     ; <double*> [#uses=2]
  %"alloca point" = bitcast i32 0 to i32          ; <i32> [#uses=0]
  store i32 %argc, i32* %argc_addr
  store i8** %argv, i8*** %argv_addr
  store double 0.000000e+00, double* %a, align 8, !dbg !0
  store double -2.500000e-01, double* %b, align 8, !dbg !0
  %1 = load double* %a, align 8, !dbg !10         ; <double> [#uses=1]
  %2 = fmul double %1, 8.000000e+00, !dbg !10     ; <double> [#uses=1]
  %3 = load double* %a, align 8, !dbg !10         ; <double> [#uses=1]
  %4 = fmul double %2, %3, !dbg !10               ; <double> [#uses=1]
  %5 = load double* %b, align 8, !dbg !10         ; <double> [#uses=1]
  %6 = fmul double %5, 4.000000e+00, !dbg !10     ; <double> [#uses=1]
  %7 = fadd double %4, %6, !dbg !10               ; <double> [#uses=1]
  %8 = fadd double %7, 1.000000e+00, !dbg !10     ; <double> [#uses=1]
  %9 = fcmp oeq double %8, 0.000000e+00, !dbg !10 ; <i1> [#uses=1]
  br i1 %9, label %bb, label %bb1, !dbg !10

bb:                                               ; preds = %entry
  %10 = call i32 @puts(i8* getelementptr inbounds ([36 x i8]* @.str, i32 0, i32 0)) nounwind, !dbg !11 ; <i32> [#uses=0]
  call void @abort() noreturn nounwind, !dbg !12
  unreachable, !dbg !12

bb1:                                              ; preds = %entry
  %11 = call i32 @puts(i8* getelementptr inbounds ([23 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !13 ; <i32> [#uses=0]
  store i32 0, i32* %0, align 4, !dbg !14
  %12 = load i32* %0, align 4, !dbg !14           ; <i32> [#uses=1]
  store i32 %12, i32* %retval, align 4, !dbg !14
  %retval2 = load i32* %retval, !dbg !14          ; <i32> [#uses=1]
  ret i32 %retval2, !dbg !14
}

declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

declare i32 @puts(i8*)

declare void @abort() noreturn nounwind

!0 = metadata !{i32 6, i32 0, metadata !1, null}
!1 = metadata !{i32 458763, metadata !2, i32 5, i32 0} ; [ DW_TAG_lexical_block ]
!2 = metadata !{i32 458798, i32 0, metadata !3, metadata !"main", metadata !"main", metadata !"main", metadata !3, i32 5, metadata !4, i1 false, i1 true, i32 0, i32 0, null, i1 false} ; [ DW_TAG_subprogram ]
!3 = metadata !{i32 458769, i32 0, i32 1, metadata !"klee_stopper.c", metadata !"/u/data/u93/mbmccorm/cs490st/project03/p2/", metadata !"4.2.1 (Based on Apple Inc. build 5658) (LLVM build 2.7)", i1 true, i1 false, metadata !"", i32 0} ; [ DW_TAG_compile_
!4 = metadata !{i32 458773, metadata !3, metadata !"", metadata !3, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !5, i32 0, null} ; [ DW_TAG_subroutine_type ]
!5 = metadata !{metadata !6, metadata !6, metadata !7}
!6 = metadata !{i32 458788, metadata !3, metadata !"int", metadata !3, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!7 = metadata !{i32 458767, metadata !3, metadata !"", metadata !3, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !8} ; [ DW_TAG_pointer_type ]
!8 = metadata !{i32 458767, metadata !3, metadata !"", metadata !3, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !9} ; [ DW_TAG_pointer_type ]
!9 = metadata !{i32 458788, metadata !3, metadata !"char", metadata !3, i32 0, i64 8, i64 8, i64 0, i32 0, i32 6} ; [ DW_TAG_base_type ]
!10 = metadata !{i32 11, i32 0, metadata !1, null}
!11 = metadata !{i32 13, i32 0, metadata !1, null}
!12 = metadata !{i32 14, i32 0, metadata !1, null}
!13 = metadata !{i32 18, i32 0, metadata !1, null}
!14 = metadata !{i32 21, i32 0, metadata !1, null}
