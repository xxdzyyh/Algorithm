//
//  TreeVC.m
//  Algorithm
//
//  Created by xiaoniu on 2019/4/22.
//  Copyright © 2019 com.learn. All rights reserved.
//

#import "TreeVC.h"

@interface TreeVC () {
    
}
    
@end

@implementation TreeVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
}

- (NSView *)firstCommonParentView:(NSView *)firstView secondView:(NSView *)secondView {
    
    if (firstView == secondView) {
        return nil;
    }
    
    if (firstView.superview == secondView || secondView.superview == firstView) {
        return nil;
    }
    
    NSView *firstParentView = firstView.superview;
    NSView *secondParentView = secondView.superview;
    
    while (firstParentView && secondParentView && secondParentView != firstParentView) {
        firstParentView = firstParentView.superview;
        secondParentView = secondParentView.superview;
    }
    
    return firstParentView;
}

@end
