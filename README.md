# fakelogos
Some logos functions for use with ZKSwizzle and jailbreak tweaks that doesn't use theos

# Example code
```objective-c
decl_group(ios7);
hook(SpringBoard)
- (void)applicationDidFinishLaunching:(id)application {
	_orig(void, application);
	NSLog(@"Global");
}
endhook

hook_group(ios7, SpringBoard)
- (void)applicationDidFinishLaunching:(id)application {
	_orig(void, application);
	NSLog(@"Group ios7");
}
endhook

ctor {
	init_group(ios7);
}
```
