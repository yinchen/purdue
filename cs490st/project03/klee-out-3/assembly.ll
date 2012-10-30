; ModuleID = 'p1.o'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32"
target triple = "i386-pc-linux-gnu"

@.str = private constant [2 x i8] c"a\00", align 1 ; <[2 x i8]*> [#uses=1]
@.str1 = private constant [2 x i8] c"b\00", align 1 ; <[2 x i8]*> [#uses=1]
@.str2 = private constant [2 x i8] c"c\00", align 1 ; <[2 x i8]*> [#uses=1]
@.str3 = private constant [2 x i8] c"d\00", align 1 ; <[2 x i8]*> [#uses=1]
@.str4 = private constant [4 x i8] c"%d\0A\00", align 1 ; <[4 x i8]*> [#uses=1]

define i32 @main() nounwind {
entry:
  %retval = alloca i32                            ; <i32*> [#uses=2]
  %0 = alloca i32                                 ; <i32*> [#uses=2]
  %e = alloca i32                                 ; <i32*> [#uses=23]
  %a = alloca i32                                 ; <i32*> [#uses=6]
  %b = alloca i32                                 ; <i32*> [#uses=7]
  %c = alloca i32                                 ; <i32*> [#uses=4]
  %d = alloca i32                                 ; <i32*> [#uses=6]
  %"alloca point" = bitcast i32 0 to i32          ; <i32> [#uses=0]
  store i32 0, i32* %e, align 4, !dbg !0
  store i32 0, i32* %a, align 4, !dbg !7
  store i32 0, i32* %b, align 4, !dbg !7
  store i32 0, i32* %c, align 4, !dbg !7
  store i32 0, i32* %d, align 4, !dbg !7
  %1 = call i32 (...)* @klee_make_symbolic(i32* %a, i32 4, i8* getelementptr inbounds ([2 x i8]* @.str, i32 0, i32 0)) nounwind, !dbg !8 ; <i32> [#uses=0]
  %2 = call i32 (...)* @klee_make_symbolic(i32* %b, i32 4, i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !9 ; <i32> [#uses=0]
  %3 = call i32 (...)* @klee_make_symbolic(i32* %c, i32 4, i8* getelementptr inbounds ([2 x i8]* @.str2, i32 0, i32 0)) nounwind, !dbg !10 ; <i32> [#uses=0]
  %4 = call i32 (...)* @klee_make_symbolic(i32* %d, i32 4, i8* getelementptr inbounds ([2 x i8]* @.str3, i32 0, i32 0)) nounwind, !dbg !11 ; <i32> [#uses=0]
  %5 = load i32* %a, align 4, !dbg !12            ; <i32> [#uses=1]
  %6 = icmp sgt i32 %5, 10, !dbg !12              ; <i1> [#uses=1]
  br i1 %6, label %bb, label %bb9, !dbg !12

bb:                                               ; preds = %entry
  %7 = load i32* %e, align 4, !dbg !13            ; <i32> [#uses=1]
  store i32 %7, i32* %e, align 4, !dbg !13
  %8 = load i32* %b, align 4, !dbg !14            ; <i32> [#uses=1]
  %9 = mul nsw i32 %8, 3, !dbg !14                ; <i32> [#uses=1]
  %10 = icmp eq i32 %9, 273, !dbg !14             ; <i1> [#uses=1]
  br i1 %10, label %bb1, label %bb2, !dbg !14

bb1:                                              ; preds = %bb
  %11 = load i32* %e, align 4, !dbg !15           ; <i32> [#uses=1]
  store i32 %11, i32* %e, align 4, !dbg !15
  br label %bb19, !dbg !15

bb2:                                              ; preds = %bb
  %12 = load i32* %a, align 4, !dbg !16           ; <i32> [#uses=1]
  %13 = load i32* %b, align 4, !dbg !16           ; <i32> [#uses=1]
  %14 = add nsw i32 %12, %13, !dbg !16            ; <i32> [#uses=1]
  %15 = icmp sgt i32 %14, 24, !dbg !16            ; <i1> [#uses=1]
  br i1 %15, label %bb3, label %bb4, !dbg !16

bb3:                                              ; preds = %bb2
  %16 = load i32* %e, align 4, !dbg !17           ; <i32> [#uses=1]
  %17 = add nsw i32 %16, 1, !dbg !17              ; <i32> [#uses=1]
  store i32 %17, i32* %e, align 4, !dbg !17
  br label %bb19, !dbg !17

bb4:                                              ; preds = %bb2
  %18 = load i32* %b, align 4, !dbg !18           ; <i32> [#uses=1]
  %19 = icmp sle i32 %18, 499, !dbg !18           ; <i1> [#uses=1]
  br i1 %19, label %bb5, label %bb6, !dbg !18

bb5:                                              ; preds = %bb4
  %20 = load i32* %e, align 4, !dbg !19           ; <i32> [#uses=1]
  %21 = add nsw i32 %20, 2, !dbg !19              ; <i32> [#uses=1]
  store i32 %21, i32* %e, align 4, !dbg !19
  br label %bb19, !dbg !19

bb6:                                              ; preds = %bb4
  %22 = load i32* %b, align 4, !dbg !20           ; <i32> [#uses=1]
  %23 = icmp sle i32 %22, 299, !dbg !20           ; <i1> [#uses=1]
  br i1 %23, label %bb7, label %bb19, !dbg !20

bb7:                                              ; preds = %bb6
  %24 = load i32* %e, align 4, !dbg !21           ; <i32> [#uses=1]
  %25 = add nsw i32 %24, 3, !dbg !21              ; <i32> [#uses=1]
  store i32 %25, i32* %e, align 4, !dbg !21
  br label %bb19, !dbg !21

bb9:                                              ; preds = %entry
  %26 = load i32* %d, align 4, !dbg !22           ; <i32> [#uses=1]
  %27 = icmp sgt i32 %26, 0, !dbg !22             ; <i1> [#uses=1]
  %28 = load i32* %e, align 4, !dbg !23           ; <i32> [#uses=2]
  br i1 %27, label %bb10, label %bb16, !dbg !22

bb10:                                             ; preds = %bb9
  %29 = add nsw i32 %28, 4, !dbg !23              ; <i32> [#uses=1]
  store i32 %29, i32* %e, align 4, !dbg !23
  %30 = load i32* %d, align 4, !dbg !24           ; <i32> [#uses=1]
  %31 = load i32* %a, align 4, !dbg !24           ; <i32> [#uses=1]
  %32 = icmp slt i32 %30, %31, !dbg !24           ; <i1> [#uses=1]
  br i1 %32, label %bb11, label %bb12, !dbg !24

bb11:                                             ; preds = %bb10
  %33 = load i32* %e, align 4, !dbg !25           ; <i32> [#uses=1]
  store i32 %33, i32* %e, align 4, !dbg !25
  br label %bb19, !dbg !25

bb12:                                             ; preds = %bb10
  %34 = load i32* %c, align 4, !dbg !26           ; <i32> [#uses=1]
  %35 = add nsw i32 %34, 10, !dbg !26             ; <i32> [#uses=1]
  %36 = load i32* %d, align 4, !dbg !26           ; <i32> [#uses=1]
  %37 = icmp slt i32 %35, %36, !dbg !26           ; <i1> [#uses=1]
  %38 = load i32* %e, align 4, !dbg !27           ; <i32> [#uses=2]
  br i1 %37, label %bb13, label %bb14, !dbg !26

bb13:                                             ; preds = %bb12
  %39 = add nsw i32 %38, 1, !dbg !27              ; <i32> [#uses=1]
  store i32 %39, i32* %e, align 4, !dbg !27
  br label %bb19, !dbg !27

bb14:                                             ; preds = %bb12
  %40 = add nsw i32 %38, 2, !dbg !28              ; <i32> [#uses=1]
  store i32 %40, i32* %e, align 4, !dbg !28
  br label %bb19, !dbg !28

bb16:                                             ; preds = %bb9
  %41 = add nsw i32 %28, 7, !dbg !29              ; <i32> [#uses=1]
  store i32 %41, i32* %e, align 4, !dbg !29
  %42 = load i32* %b, align 4, !dbg !30           ; <i32> [#uses=1]
  %43 = mul nsw i32 %42, 3, !dbg !30              ; <i32> [#uses=1]
  %44 = load i32* %a, align 4, !dbg !30           ; <i32> [#uses=1]
  %45 = add nsw i32 %43, %44, !dbg !30            ; <i32> [#uses=1]
  %46 = load i32* %c, align 4, !dbg !30           ; <i32> [#uses=1]
  %47 = mul nsw i32 %46, 2, !dbg !30              ; <i32> [#uses=1]
  %48 = load i32* %d, align 4, !dbg !30           ; <i32> [#uses=1]
  %49 = add nsw i32 %47, %48, !dbg !30            ; <i32> [#uses=1]
  %50 = icmp slt i32 %45, %49, !dbg !30           ; <i1> [#uses=1]
  %51 = load i32* %e, align 4, !dbg !31           ; <i32> [#uses=2]
  br i1 %50, label %bb17, label %bb18, !dbg !30

bb17:                                             ; preds = %bb16
  store i32 %51, i32* %e, align 4, !dbg !31
  br label %bb19, !dbg !31

bb18:                                             ; preds = %bb16
  %52 = add nsw i32 %51, 1, !dbg !32              ; <i32> [#uses=1]
  store i32 %52, i32* %e, align 4, !dbg !32
  br label %bb19, !dbg !32

bb19:                                             ; preds = %bb11, %bb13, %bb14, %bb1, %bb3, %bb5, %bb6, %bb7, %bb18, %bb17
  %53 = load i32* %e, align 4, !dbg !33           ; <i32> [#uses=1]
  %54 = call i32 (i8*, ...)* @printf(i8* noalias getelementptr inbounds ([4 x i8]* @.str4, i32 0, i32 0), i32 %53) nounwind, !dbg !33 ; <i32> [#uses=0]
  store i32 0, i32* %0, align 4, !dbg !34
  %55 = load i32* %0, align 4, !dbg !34           ; <i32> [#uses=1]
  store i32 %55, i32* %retval, align 4, !dbg !34
  %retval20 = load i32* %retval, !dbg !34         ; <i32> [#uses=1]
  ret i32 %retval20, !dbg !34
}

declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

declare i32 @klee_make_symbolic(...)

declare i32 @printf(i8* noalias, ...) nounwind

!0 = metadata !{i32 6, i32 0, metadata !1, null}
!1 = metadata !{i32 458763, metadata !2, i32 4, i32 0} ; [ DW_TAG_lexical_block ]
!2 = metadata !{i32 458798, i32 0, metadata !3, metadata !"main", metadata !"main", metadata !"main", metadata !3, i32 4, metadata !4, i1 false, i1 true, i32 0, i32 0, null, i1 false} ; [ DW_TAG_subprogram ]
!3 = metadata !{i32 458769, i32 0, i32 1, metadata !"p1.c", metadata !"/u/data/u93/mbmccorm/cs490st/project03/", metadata !"4.2.1 (Based on Apple Inc. build 5658) (LLVM build 2.7)", i1 true, i1 false, metadata !"", i32 0} ; [ DW_TAG_compile_unit ]
!4 = metadata !{i32 458773, metadata !3, metadata !"", metadata !3, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !5, i32 0, null} ; [ DW_TAG_subroutine_type ]
!5 = metadata !{metadata !6}
!6 = metadata !{i32 458788, metadata !3, metadata !"int", metadata !3, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!7 = metadata !{i32 7, i32 0, metadata !1, null}
!8 = metadata !{i32 9, i32 0, metadata !1, null}
!9 = metadata !{i32 10, i32 0, metadata !1, null}
!10 = metadata !{i32 11, i32 0, metadata !1, null}
!11 = metadata !{i32 12, i32 0, metadata !1, null}
!12 = metadata !{i32 14, i32 0, metadata !1, null}
!13 = metadata !{i32 15, i32 0, metadata !1, null}
!14 = metadata !{i32 17, i32 0, metadata !1, null}
!15 = metadata !{i32 18, i32 0, metadata !1, null}
!16 = metadata !{i32 20, i32 0, metadata !1, null}
!17 = metadata !{i32 21, i32 0, metadata !1, null}
!18 = metadata !{i32 23, i32 0, metadata !1, null}
!19 = metadata !{i32 24, i32 0, metadata !1, null}
!20 = metadata !{i32 26, i32 0, metadata !1, null}
!21 = metadata !{i32 27, i32 0, metadata !1, null}
!22 = metadata !{i32 30, i32 0, metadata !1, null}
!23 = metadata !{i32 31, i32 0, metadata !1, null}
!24 = metadata !{i32 33, i32 0, metadata !1, null}
!25 = metadata !{i32 34, i32 0, metadata !1, null}
!26 = metadata !{i32 36, i32 0, metadata !1, null}
!27 = metadata !{i32 37, i32 0, metadata !1, null}
!28 = metadata !{i32 40, i32 0, metadata !1, null}
!29 = metadata !{i32 44, i32 0, metadata !1, null}
!30 = metadata !{i32 46, i32 0, metadata !1, null}
!31 = metadata !{i32 47, i32 0, metadata !1, null}
!32 = metadata !{i32 50, i32 0, metadata !1, null}
!33 = metadata !{i32 54, i32 0, metadata !1, null}
!34 = metadata !{i32 56, i32 0, metadata !1, null}
