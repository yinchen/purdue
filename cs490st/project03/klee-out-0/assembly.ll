; ModuleID = 'p1.o'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32"
target triple = "i386-pc-linux-gnu"

@.str = private constant [2 x i8] c"a\00", align 1 ; <[2 x i8]*> [#uses=1]
@.str1 = private constant [4 x i8] c"%d\0A\00", align 1 ; <[4 x i8]*> [#uses=1]

define i32 @main() nounwind {
entry:
  %retval = alloca i32                            ; <i32*> [#uses=2]
  %0 = alloca i32                                 ; <i32*> [#uses=2]
  %e = alloca i32                                 ; <i32*> [#uses=23]
  %a = alloca i32                                 ; <i32*> [#uses=6]
  %b = alloca i32                                 ; <i32*> [#uses=6]
  %c = alloca i32                                 ; <i32*> [#uses=3]
  %d = alloca i32                                 ; <i32*> [#uses=5]
  %"alloca point" = bitcast i32 0 to i32          ; <i32> [#uses=0]
  store i32 0, i32* %e, align 4, !dbg !0
  store i32 0, i32* %a, align 4, !dbg !7
  store i32 0, i32* %b, align 4, !dbg !7
  store i32 0, i32* %c, align 4, !dbg !7
  store i32 0, i32* %d, align 4, !dbg !7
  %1 = call i32 (...)* @klee_make_symbolic(i32* %a, i32 4, i8* getelementptr inbounds ([2 x i8]* @.str, i32 0, i32 0)) nounwind, !dbg !8 ; <i32> [#uses=0]
  %2 = load i32* %a, align 4, !dbg !9             ; <i32> [#uses=1]
  %3 = icmp sgt i32 %2, 10, !dbg !9               ; <i1> [#uses=1]
  br i1 %3, label %bb, label %bb9, !dbg !9

bb:                                               ; preds = %entry
  %4 = load i32* %e, align 4, !dbg !10            ; <i32> [#uses=1]
  store i32 %4, i32* %e, align 4, !dbg !10
  %5 = load i32* %b, align 4, !dbg !11            ; <i32> [#uses=1]
  %6 = mul nsw i32 %5, 3, !dbg !11                ; <i32> [#uses=1]
  %7 = icmp eq i32 %6, 273, !dbg !11              ; <i1> [#uses=1]
  br i1 %7, label %bb1, label %bb2, !dbg !11

bb1:                                              ; preds = %bb
  %8 = load i32* %e, align 4, !dbg !12            ; <i32> [#uses=1]
  store i32 %8, i32* %e, align 4, !dbg !12
  br label %bb19, !dbg !12

bb2:                                              ; preds = %bb
  %9 = load i32* %a, align 4, !dbg !13            ; <i32> [#uses=1]
  %10 = load i32* %b, align 4, !dbg !13           ; <i32> [#uses=1]
  %11 = add nsw i32 %9, %10, !dbg !13             ; <i32> [#uses=1]
  %12 = icmp sgt i32 %11, 24, !dbg !13            ; <i1> [#uses=1]
  br i1 %12, label %bb3, label %bb4, !dbg !13

bb3:                                              ; preds = %bb2
  %13 = load i32* %e, align 4, !dbg !14           ; <i32> [#uses=1]
  %14 = add nsw i32 %13, 1, !dbg !14              ; <i32> [#uses=1]
  store i32 %14, i32* %e, align 4, !dbg !14
  br label %bb19, !dbg !14

bb4:                                              ; preds = %bb2
  %15 = load i32* %b, align 4, !dbg !15           ; <i32> [#uses=1]
  %16 = icmp sle i32 %15, 499, !dbg !15           ; <i1> [#uses=1]
  br i1 %16, label %bb5, label %bb6, !dbg !15

bb5:                                              ; preds = %bb4
  %17 = load i32* %e, align 4, !dbg !16           ; <i32> [#uses=1]
  %18 = add nsw i32 %17, 2, !dbg !16              ; <i32> [#uses=1]
  store i32 %18, i32* %e, align 4, !dbg !16
  br label %bb19, !dbg !16

bb6:                                              ; preds = %bb4
  %19 = load i32* %b, align 4, !dbg !17           ; <i32> [#uses=1]
  %20 = icmp sle i32 %19, 299, !dbg !17           ; <i1> [#uses=1]
  br i1 %20, label %bb7, label %bb19, !dbg !17

bb7:                                              ; preds = %bb6
  %21 = load i32* %e, align 4, !dbg !18           ; <i32> [#uses=1]
  %22 = add nsw i32 %21, 3, !dbg !18              ; <i32> [#uses=1]
  store i32 %22, i32* %e, align 4, !dbg !18
  br label %bb19, !dbg !18

bb9:                                              ; preds = %entry
  %23 = load i32* %d, align 4, !dbg !19           ; <i32> [#uses=1]
  %24 = icmp sgt i32 %23, 0, !dbg !19             ; <i1> [#uses=1]
  %25 = load i32* %e, align 4, !dbg !20           ; <i32> [#uses=2]
  br i1 %24, label %bb10, label %bb16, !dbg !19

bb10:                                             ; preds = %bb9
  %26 = add nsw i32 %25, 4, !dbg !20              ; <i32> [#uses=1]
  store i32 %26, i32* %e, align 4, !dbg !20
  %27 = load i32* %a, align 4, !dbg !21           ; <i32> [#uses=1]
  %28 = load i32* %d, align 4, !dbg !21           ; <i32> [#uses=1]
  %29 = icmp slt i32 %28, %27, !dbg !21           ; <i1> [#uses=1]
  br i1 %29, label %bb11, label %bb12, !dbg !21

bb11:                                             ; preds = %bb10
  %30 = load i32* %e, align 4, !dbg !22           ; <i32> [#uses=1]
  store i32 %30, i32* %e, align 4, !dbg !22
  br label %bb19, !dbg !22

bb12:                                             ; preds = %bb10
  %31 = load i32* %c, align 4, !dbg !23           ; <i32> [#uses=1]
  %32 = add nsw i32 %31, 10, !dbg !23             ; <i32> [#uses=1]
  %33 = load i32* %d, align 4, !dbg !23           ; <i32> [#uses=1]
  %34 = icmp slt i32 %32, %33, !dbg !23           ; <i1> [#uses=1]
  %35 = load i32* %e, align 4, !dbg !24           ; <i32> [#uses=2]
  br i1 %34, label %bb13, label %bb14, !dbg !23

bb13:                                             ; preds = %bb12
  %36 = add nsw i32 %35, 1, !dbg !24              ; <i32> [#uses=1]
  store i32 %36, i32* %e, align 4, !dbg !24
  br label %bb19, !dbg !24

bb14:                                             ; preds = %bb12
  %37 = add nsw i32 %35, 2, !dbg !25              ; <i32> [#uses=1]
  store i32 %37, i32* %e, align 4, !dbg !25
  br label %bb19, !dbg !25

bb16:                                             ; preds = %bb9
  %38 = add nsw i32 %25, 7, !dbg !26              ; <i32> [#uses=1]
  store i32 %38, i32* %e, align 4, !dbg !26
  %39 = load i32* %b, align 4, !dbg !27           ; <i32> [#uses=1]
  %40 = mul nsw i32 %39, 3, !dbg !27              ; <i32> [#uses=1]
  %41 = load i32* %a, align 4, !dbg !27           ; <i32> [#uses=1]
  %42 = add nsw i32 %40, %41, !dbg !27            ; <i32> [#uses=1]
  %43 = load i32* %c, align 4, !dbg !27           ; <i32> [#uses=1]
  %44 = mul nsw i32 %43, 2, !dbg !27              ; <i32> [#uses=1]
  %45 = load i32* %d, align 4, !dbg !27           ; <i32> [#uses=1]
  %46 = add nsw i32 %44, %45, !dbg !27            ; <i32> [#uses=1]
  %47 = icmp slt i32 %42, %46, !dbg !27           ; <i1> [#uses=1]
  %48 = load i32* %e, align 4, !dbg !28           ; <i32> [#uses=2]
  br i1 %47, label %bb17, label %bb18, !dbg !27

bb17:                                             ; preds = %bb16
  store i32 %48, i32* %e, align 4, !dbg !28
  br label %bb19, !dbg !28

bb18:                                             ; preds = %bb16
  %49 = add nsw i32 %48, 1, !dbg !29              ; <i32> [#uses=1]
  store i32 %49, i32* %e, align 4, !dbg !29
  br label %bb19, !dbg !29

bb19:                                             ; preds = %bb11, %bb13, %bb14, %bb1, %bb3, %bb5, %bb6, %bb7, %bb18, %bb17
  %50 = load i32* %e, align 4, !dbg !30           ; <i32> [#uses=1]
  %51 = call i32 (i8*, ...)* @printf(i8* noalias getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %50) nounwind, !dbg !30 ; <i32> [#uses=0]
  store i32 0, i32* %0, align 4, !dbg !31
  %52 = load i32* %0, align 4, !dbg !31           ; <i32> [#uses=1]
  store i32 %52, i32* %retval, align 4, !dbg !31
  %retval20 = load i32* %retval, !dbg !31         ; <i32> [#uses=1]
  ret i32 %retval20, !dbg !31
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
!9 = metadata !{i32 11, i32 0, metadata !1, null}
!10 = metadata !{i32 12, i32 0, metadata !1, null}
!11 = metadata !{i32 14, i32 0, metadata !1, null}
!12 = metadata !{i32 15, i32 0, metadata !1, null}
!13 = metadata !{i32 17, i32 0, metadata !1, null}
!14 = metadata !{i32 18, i32 0, metadata !1, null}
!15 = metadata !{i32 20, i32 0, metadata !1, null}
!16 = metadata !{i32 21, i32 0, metadata !1, null}
!17 = metadata !{i32 23, i32 0, metadata !1, null}
!18 = metadata !{i32 24, i32 0, metadata !1, null}
!19 = metadata !{i32 27, i32 0, metadata !1, null}
!20 = metadata !{i32 28, i32 0, metadata !1, null}
!21 = metadata !{i32 30, i32 0, metadata !1, null}
!22 = metadata !{i32 31, i32 0, metadata !1, null}
!23 = metadata !{i32 33, i32 0, metadata !1, null}
!24 = metadata !{i32 34, i32 0, metadata !1, null}
!25 = metadata !{i32 37, i32 0, metadata !1, null}
!26 = metadata !{i32 41, i32 0, metadata !1, null}
!27 = metadata !{i32 43, i32 0, metadata !1, null}
!28 = metadata !{i32 44, i32 0, metadata !1, null}
!29 = metadata !{i32 47, i32 0, metadata !1, null}
!30 = metadata !{i32 51, i32 0, metadata !1, null}
!31 = metadata !{i32 53, i32 0, metadata !1, null}
