//
//  fakelogos.h
//
//
//  Created by Mustafa Gezen on 04.08.2015.
//  Copyright © 2015 Mustafa Gezen. All rights reserved.
//

#define decl_group(x) NSMutableArray *_## x

#define hook_group(GROUP_NAME, TARGET_NAME) \
__attribute__((constructor (102))) void _$##GROUP_NAME##CTOR() { \
if (! _##GROUP_NAME) _##GROUP_NAME = [[NSMutableArray alloc] init]; \
[_##GROUP_NAME addObject:[NSString stringWithFormat:@"_$%s_%s__", # GROUP_NAME, # TARGET_NAME]]; \
} \
@interface _$##GROUP_NAME##_##TARGET_NAME##_ : NSObject @end \
@implementation _$##GROUP_NAME##_##TARGET_NAME##_ \
+ (void)initialize {} \
@end \
@interface _$##GROUP_NAME##_##TARGET_NAME##__ : _$##GROUP_NAME##_##TARGET_NAME##_ @end \
@implementation _$##GROUP_NAME##_##TARGET_NAME##__ (FAKELOGOS) \
+ (void)__load { \
ZKSwizzle(_$##GROUP_NAME##_##TARGET_NAME##__, TARGET_NAME); \
} \
@end \
@implementation _$##GROUP_NAME##_##TARGET_NAME##__

#define init_group(x) \
for (NSString *key in _## x) { \
[NSClassFromString(key) __load]; \
}

#define hook(TARGET_NAME) ZKSwizzleInterface(_## TARGET_NAME,TARGET_NAME, NSObject); \
@implementation _## TARGET_NAME
#define endhook @end

#define ctor __attribute__((constructor (103))) void init()

#define hook_class(TARGET_NAME) ZKSwizzle(TARGET_NAME, NSStringFromClass([self class]))

#define _orig(TYPE, ...) ZKOrig(TYPE, ##__VA_ARGS__)
