# fakelogos
Some logos functions for use with ZKSwizzle and jailbreak tweaks that doesn't use theos

# Example code
```objective-c
hook(SpringBoard)
- (void)applicationDidFinishLaunching:(id)application {
	ZKOrig(void, application);
	NSLog(@"Global");
}
endhook

hook_group(ios7, SpringBoard)
- (void)applicationDidFinishLaunching:(id)application {
	ZKOrig(void, application);
	NSLog(@"Group ios7");
}
endhook

ctor {
	_def_group(ios7);
	add_to_group(ios7, SpringBoard);
	init_group(ios7);
}
```
